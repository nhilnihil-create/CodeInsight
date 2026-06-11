#include <iostream>
using namespace std;
typedef long long int LLI;

int main()
{
	LLI n, d, x, sum = 0, tmp;
	cin >> n >> d >> x;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		sum += 1 + (d-1)/tmp;
	}
	cout << sum + x;
}