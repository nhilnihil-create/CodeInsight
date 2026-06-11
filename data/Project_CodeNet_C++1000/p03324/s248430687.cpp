#include<iostream>
using namespace std;

int main() { 
		int d, n;
	cin >> d >> n;
	if (n == 100)
		n++;
	if (d == 0)
	{
		cout << n << endl;
	}
	else if (d == 1)
		cout << n * 100 << endl;
	else
		cout << n * 10000 << endl;
		
}
