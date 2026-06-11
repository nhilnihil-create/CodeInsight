#include <iostream>
using namespace std;

int a, b;

int main()
{
	cin >> a >> b;
	if(!(b % a))
		cout << a + b;
	else
		cout << b - a;
	return 0;
}