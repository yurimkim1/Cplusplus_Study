//#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>//cin, cout
#include <fstream>//ofstream, ifstream

#include <string>

int main()
{
	//cin과 멤버함수
	if (0)
	{
		int age = 0;
		cout << "나이를 입력하세요 : ";

		if (0)
		{
			//1회성
			cin >> age;//'a'를 입력하면?

			if (cin.fail())
				cout << "입력실패" << endl;
			else
				cout << "입력성공 : " << age << endl;
		}

		while (1)
		{
			cin >> age;
			if (cin.fail())
			{
				cin.clear(); // cin의 상태를 clear한다
				cin.ignore(100, '\n'); //입력버퍼를 비운다
				continue;
			}
			break;
		}
		cout << "입력성공 : " << age << endl;
	}

	// 단어입력 vs 문장입력
	if (0)
	{
		string name;
		cout << "이름을 입력하세요 : ";
		//cin >> name;//"강 호동"을 입력하면 어떻게 될까?
		//cout << name << endl;

		std::getline(cin, name);
		cout << name << endl;

	}

	//파일 입력 - ofstream + text모드
	if (0)
	{
		cout << "hello" << endl;

		ofstream f("c:\\temp\\a.txt");
		f << "hello" << endl;
		f << "hi" << endl;
		f << "hello" << endl;
	}

	//파일 출력 - ifstream + text모드
	if (0)
	{
		ifstream f("c:\\temp\\a.txt");

		string content;

		while (getline(f, content))
		{
			cout << content;
		}
	}

	//파일 입출력 - ifstream/ofstream + binary모드
	if (1)
	{
		class Human
		{
		public:
			string name;
			int age;
		};
		Human a;
		a.name = "홍길동";
		a.age = 22;
		///////////////////////
		//파일저장
		ofstream f1("c:\\temp\\bin.dat", std::ios::binary);

		f1.write((const char*)&a, sizeof(Human)); //시작부터 끝까지
		f1.close();

		/////////////////////
		//파일로드
		Human b;
		cout << "before" << endl;
		cout << b.name << endl;
		cout << b.age << endl;

		ifstream f2("c:\\temp\\bin.dat", std::ios::binary);
		if (f2.is_open())
		{
			f2.read((char*)&b, sizeof(Human));
			f2.close();
		}
		cout << "after" << endl;
		cout << b.name << endl;
		cout << b.age << endl;

	}

	return 0;
}

#endif