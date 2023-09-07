#include <iostream>
using namespace std;
class Student
{
private:
	char* name;
	int age;
	char* email;

public:
	Student()
	{
		cout << "Constructor by default " << endl;
		name = nullptr;
		age = 0;
		email = nullptr;
	}

	Student(const char* n, int a) //oleg20
	{
		name = new char[strlen(n) + 1]; //выделяем память при создании объекта
		strcpy_s(name, strlen(n) + 1, n);
		age = a;
		email = nullptr;
		cout << "Concstructor 2 params" << endl;
	}

	Student(const char* n, int a, const char* e)
	{
		name = new char[strlen(n) + 1]; //выделяем память при создании объекта
		strcpy_s(name, strlen(n) + 1, n);
		age = a;
		email = new char[strlen(e) + 1];
		strcpy_s(email, strlen(e) + 1, e);
	}

	void Print()
	{
		cout << "Name: " << name << endl << "Age: " << age << endl << "Email: " << email << endl << endl;
	}
	~Student()
	{
		delete[] name; // явно освобождаем память при уничтожении объекта..
		delete[] email;
		cout << "Desctructor email name." << endl;
	}



	void Input()
	{
		char buff[20];
		cout << "Enter name: ";
		cin >> buff;
		if (name != nullptr)
		{
			cout << "Delete - > " << name << "... " << endl;
			delete[] name;
		}
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);
		cout << "Enter age: ";
		cin >> age;
		cout << "Enter email: ";
		cin >> buff;
		if (email != nullptr)
		{
			cout << "Delete - > " << email << "..." << endl;
			delete[] email;
		}
		email = new char[strlen(buff) + 1];
		strcpy_s(email, strlen(buff) + 1, buff);
	}
	// не работает
	 /*void SetName()
	 {

	 }
	 int GetName(string _name)
	 {
	  _name = name;
	 }
	 int GetAge(int _age)
	 {
	  _age = age;
	 }
	 int GetEmail(string _email)
	 {
	  _email = email;
	 }*/

	 //Добавить поле эмейл (char*)
	 //конструктор с 3 параметрами
	 //методы аксессоры
	 //удаление выделенной динамической памяти в деструкторе
};
int main()
{
	Student b("Oleg", 20, "email");
	b.Input();
	b.Print();

}