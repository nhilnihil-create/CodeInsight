#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int LLI;

int main()
{
	char x, y;
	cin >> x >> y;
	if( x > y )
		cout << ">";
	else if( x < y )
		cout << "<";
	else
		cout << "=";
}