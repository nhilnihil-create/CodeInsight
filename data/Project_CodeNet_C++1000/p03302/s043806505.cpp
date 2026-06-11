#include <iostream>
using namespace std;

int main()
{
	int a, b;

	cin >> a;
	cin >> b;

	if (a + b == 15)
		cout << "+";
	if (a*b == 15)
		cout << "*";
	else if((a+b!=15)&&(a*b!=15))
	{
		cout << "x";
	}
}