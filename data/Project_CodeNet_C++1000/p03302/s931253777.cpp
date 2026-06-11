#include<cstdio>
#include<iostream>

using namespace std;

int a, b;

int main ()
{
	cin >> a >> b;
	if (a + b == 15) { cout << "+\n"; return 0;}
	else if (a * b == 15) { cout << "*\n"; return 0;}
	else cout << "x\n";
	return 0;
}