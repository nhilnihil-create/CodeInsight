#include <iostream>
using namespace std;

int main()
{
	int a, b;
	char t;

	cin >> a >> b;

	if (a + b == 15)
		t = '+';
	else if (a * b == 15)
		t = '*';
	else
		t = 'x';

	cout << t << endl;

	return 0;
}