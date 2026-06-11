#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main()
{	string a;
	cin >> a;
	int b = 700;
	if (a[0] == 'o')
		b += 100;
	if (a[1] == 'o')
		b += 100;
	if (a[2] == 'o')
		b += 100;
	cout << b;
}