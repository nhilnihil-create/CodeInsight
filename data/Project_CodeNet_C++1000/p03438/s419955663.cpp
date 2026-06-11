#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	long long sum_a, sum_b, diff;
	int n;
	cin >> n;
	int a[n], b[n];

	sum_a = sum_b = 0;
	rep(i, n) 
	{
		cin >> a[i];
		sum_a += a[i];
	}
	rep(i, n) 
	{
		cin >> b[i];
		sum_b += b[i];
	}
	diff = 0;
	rep(i, n)
	{
		if (a[i] < b[i])
		{
			diff += (b[i] - a[i]) / 2;
			if ((b[i] - a[i]) % 2 != 0)
				diff++;
		}
	}
	if (diff <= sum_b - sum_a)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
