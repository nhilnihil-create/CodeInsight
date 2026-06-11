#include <iostream>
using namespace std;

int main()
{
	int A, b = 0;

		cin >> A;

	if (A > 99)
		b++;

	if (A % 100 > 9)
		b++;

	if (A % 10 > 0)
		b++;

	cout << b << endl;
}
