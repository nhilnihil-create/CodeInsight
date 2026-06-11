#include <iostream>
using namespace std;

int main()
{
	long long int x;
	cin >> x;
	if( x % 2 == 1 )
		cout << 2*x;
	else cout << x;
}