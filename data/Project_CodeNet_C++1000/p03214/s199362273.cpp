#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, sum, ans;
	cin >> n;
	int a[n];
	sum = 0;
	rep(i, n)
	{
		cin >> a[i];
		sum += a[i];
	}
	double ave, mn;
	ave = (double)sum / n;
	mn = 1e9;
	rep(i, n)
	{
		double b = abs((double)ave - a[i]);
		if (mn > b)
		{
			mn = b;
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}
