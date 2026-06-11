#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, m;
	cin >> n;
	m = n * (n - 1) / 2;
	m -= n / 2;
	cout << m << endl;
	for(int i = 1; i <= n - 1; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			if (n % 2 == 1)
			{
				if (i + j != n)
					cout << i << " " << j << endl;
			}
			else
			{
				if (i + j != n + 1)
					cout << i << " " << j << endl;
			}
		}
	}
}
