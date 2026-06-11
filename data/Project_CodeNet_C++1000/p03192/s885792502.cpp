#include <iostream>
using namespace std;
int main()
{
	int n, sum = 0;
	cin >> n;
	if (n % 10 == 2)
	{
		sum++;
	}
	if (n / 10 % 10 == 2)
	{
		sum ++;
	}
	if (n / 100 % 10 == 2)
	{
		sum++;
	}
	if (n / 1000 == 2)
	{
		sum++;
	}
	cout << sum << endl;
	return 0;
}