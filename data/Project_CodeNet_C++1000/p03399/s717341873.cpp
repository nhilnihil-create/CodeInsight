#include <iostream>
using namespace std;
typedef long long int LLI;

int main()
{
	int a, b, c, d, first, second;
	cin >> a >> b >> c >> d;
	if( a > b )
		first = b;
	else first = a;
	
	if( c > d )
		second = d;
	else second = c;
	cout << first + second;
}