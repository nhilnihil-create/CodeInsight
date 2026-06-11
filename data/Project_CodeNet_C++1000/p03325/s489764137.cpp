#include <iostream>
using namespace std;
typedef long long int LLI;

int main()
{
	LLI n, sum = 0;
	cin >> n;
	LLI a;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		while( a % 2 == 0 )
		{
			sum++;
			a /= 2;
		}
	}
	cout << sum;
}