#include <iostream>
#include <cmath>
using namespace std;
typedef long long int LLI;

int main()
{
	int a, n;
	cin >> n >> a;
	if( a < n % 500 )
		cout << "No";
	else cout << "Yes";
}