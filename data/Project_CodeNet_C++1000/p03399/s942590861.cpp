#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main()
{	int a , b , c , d;
	cin >> a >> b >> c >> d;
	a = min(a , b);
	b = min(c , d);
	cout << a + b;
}