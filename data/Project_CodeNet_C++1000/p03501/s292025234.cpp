#include <iostream>
#include <vector>
using namespace std;
typedef long long int LLI;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	if( a * n < b )
		cout << a * n;
	else
		cout << b;
}