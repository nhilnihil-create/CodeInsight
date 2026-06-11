#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main()
{	int a , b , c , d , e;
	cin >> a >> b;
	c = a + b;
	d = a - b;
	e = a * b;
	a = max(c , d);
	a = max(a , e);
	cout << a;
}