#include <iostream>
using namespace std;

int a,b;

int main()
{
	cin >> a;
	cin >> b;
	const char* gg = ((a * b) % 2 == 0) ? "Even" : "Odd";
	cout << gg;
	return 0;
}