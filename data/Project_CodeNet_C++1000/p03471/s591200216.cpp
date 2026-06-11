#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string>	
using namespace std;
typedef long long ll;
const int Max = 1e5 + 5;

int main()
{
	int n, y;
	cin >> n >> y;
	int f = 0;
	for (int i = 0; i <= y / 10000; i++)
	{
		for (int j = 0; j <= y / 5000; j++)
		{
			if (i + j > n)continue;
			if ((n - i - j) * 1000 + i * 10000 + 5000 * j == y)
			{
				cout << i << " " << j << " " << n - i - j;
				return 0;
			}
		}
	}
	if (f == 0)cout << -1 << " " << -1 << " " << -1;
}