// list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;
struct ListNode
{
    ListNode* next = nullptr;
    ListNode* before = nullptr;
    int data = 0;
};
ListNode* create_List(int le) {
    ListNode *p_begin = new ListNode;
    ListNode* p;
    ListNode* n;
    p = p_begin;
    for (int i = 1; i <= le; i++)
    {
        p->next = new ListNode;
        p->data = rand() % 1000;
        p->next->before = p;
        p = p->next;
        //p->next = new ListNode;
        //p->data = rand()%1000;
        //p = p->next;
    }
    return p_begin;
}
void print_ListBegin(ListNode* p_begin) {
    ListNode* p, n;
    p = p_begin;
    while (p->next != nullptr) {
        //cout << p->next << endl;
        cout << p->data << endl;
        p = p->next;
    }
}

void print_ListBack(ListNode* p_begin) {
    ListNode* p, n;
    p = p_begin;
    while (p->next != nullptr) {
        //cout << p->next << endl;
        //cout << p->data << endl;
        p = p->next;
    }
    while (p->before != nullptr) {
        //cout << p->next << endl;
        p = p->before;
        cout << p->data << endl;
        
    }
}
int get_length_List(ListNode* p_begin) {
    ListNode* p, n;
    int i = 0;
    p = p_begin;
    while (p->next != nullptr) {
        //cout << p->next << endl;
        i++;
        //cout << p->data << endl;
        p = p->next;
    }
    return i;
}
void delete_List(ListNode*& p_begin) {
    ListNode* p = p_begin;
    while (p != nullptr) {
        ListNode* n = p->next; // Сохраняем следующий узел
        delete p;                 // Удаляем текущий
        p = n;                 // Переходим к следующему
    }
    p_begin = nullptr;
    //return nullptr;
}
void add_Node_back(ListNode* p_begin, int x) {
    ListNode* p;
    ListNode* n;
    p = p_begin;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = new ListNode;
    p->data = x;
    p->next->before = p;
   // p->before = p->next;
    p->next->next = nullptr;
    // cout << p->next << endl;

     //cout << p->next << endl;


}
void add_Node_begin(ListNode*& p_begin, int x) {
    ListNode* p;
    ListNode* n;
    ListNode* asd;
    p = p_begin;
    asd = new ListNode;
    asd->data = x;
    asd->next = p;
    asd->before = nullptr;
    p->before = asd;
    p_begin = asd;
    // cout << p->next << endl;

     //cout << p->next << endl;


}
void add_Node(ListNode*& p_begin, int number_i, int x) {
    ListNode* p;
    ListNode* n;
    p = p_begin;
    if (number_i >= get_length_List(p_begin)) {
        add_Node_back(p_begin, x);
    }
    else {
        if (number_i <= 1) {
            add_Node_begin(p_begin, x);
        }
        else {
            p = p_begin;
            for (int i = 1; i < number_i - 1; i++)
            {
                p = p->next;

            }
            ListNode* asd = new ListNode;
            asd->data = x;
            asd->next = p->next;
            //asd->next = p->next->next  неизвестно почему 
            
            p->next->before = asd;
            asd->before = p;
            p->next = asd;
            //cout << p->data << endl;

        }

    }





}
void remove_Node(ListNode*& p_begin, int number_i) {

    ListNode* p;
    ListNode* n;
    p = p_begin;
    if (number_i >= get_length_List(p_begin)) {
        p = p_begin;
        for (int i = 1; i < get_length_List(p_begin); i++)
        {
            p = p->next;

        }
        n = p;
        delete p->next->next;
        n->next = nullptr;
    }
    else {
        if (number_i <= 1) {
            ListNode* t = p_begin;
            p_begin = p_begin->next;
            delete t;

        }
        else {
            cout << get_length_List(p_begin) << endl;

            ListNode* p = p_begin;

            for (int i = 1; i < number_i - 1; i++) {
                p = p->next;
            }
            ListNode* d = p->next;
            p->next = d->next;
            delete d;
            /*

                p = p_begin;
                for (int i = 1; i <= number_i - 2; i++)
                {
                    p = p->next;

                }
                ListNode* d;
                d = p;
                d->next = d->next->next;
                //delete d->next;
                */


                //cout << p->data << endl;

        }
    }



}
int main(){
                srand(time(NULL));
                ListNode* p_list = nullptr;
                cout << "Hello user" << endl;
                bool k = true;
                int op = 0;
                int size = 0;
                do
                {
                    cout << "Choose operations" << endl;

                    cout << "1 is Create List" << endl;
                    cout << "2 is print Listbegin" << endl;
                    cout << "3 is print Listback" << endl;
                    cout << "4 delete List" << endl;
                    cout << "5 is add new element to List" << endl;
                    cout << "6 is delete  element from List" << endl;
                    cout << "0 is finish" << endl;

                    cin >> op;
                    switch (op)
                    {
                    case 1:
                        cout << "Create List" << endl;
                        cout << "Input  size of List" << endl;
                        cin >> size;
                        p_list = create_List(size);
                        cout << "Creation is done" << endl;
                        break;
                    case 2:
                        cout << "Print List Begin" << endl;
                        if (p_list != nullptr) {
                            print_ListBegin(p_list);
                            cout << "Print is done" << endl;
                        }
                        else {
                            cout << "Error " << endl;
                            cout << "List is null" << endl;
                        }
                        break;
                    case 3:
                        cout << "Print List Back" << endl;
                        if (p_list != nullptr) {
                            print_ListBack(p_list);
                        }
                        else {
                            cout << "Error " << endl;
                            cout << "List is null" << endl;
                        }
                        break;
                    case 4:
                        cout << "Delete List" << endl;
                        if (p_list != nullptr) {
                            delete_List(p_list);
                        }
                        else {
                            cout << "Error " << endl;
                            cout << "List is null" << endl;
                        }

                        break;
                    case 5:
                        cout << "add  element to List" << endl;
                        if (p_list != nullptr) {
                            cout << "Please input number that you add  " << endl;
                            int elem = 0;
                            cin >> elem;
                            cout << "Please input place" << endl;
                            int place = 0;
                            cin >> place;
                            //place--;
                            add_Node(p_list, place, elem);
                        }
                        else {
                            cout << "Error " << endl;
                            cout << "List is null" << endl;
                        }
                        break;
                    case 0:
                        cout << "Thank for using" << endl;
                        cout << "GoodBye" << endl;
                        k = false;
                        break;
                    case -1:
                        cout << get_length_List(p_list) << endl;

                        // cout << "GoodBye" << endl;
                         //k = false;
                        break;
                    default:
                        break;
                    }

                } while (k);
              

            }

            // Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
            // Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

            // Советы по началу работы 
            //   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
            //   2. В окне Team Explorer можно подключиться к системе управления версиями.
            //   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
            //   4. В окне "Список ошибок" можно просматривать ошибки.
            //   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
            //   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.