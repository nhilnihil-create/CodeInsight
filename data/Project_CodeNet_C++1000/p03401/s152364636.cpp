#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n;
	long long ans, sum;
	cin >> n;
	int a[n + 2];

	sum = 0;
	a[0] = a[n + 1] = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += abs(a[i] - a[i - 1]);
	}
	sum += abs(a[n + 1] - a[n]);
	for(int i = 1; i <= n; i++)
	{
		ans = sum;
		ans -= abs(a[i] - a[i - 1]);
		ans -= abs(a[i + 1] - a[i]);
		ans += abs(a[i - 1] - a[i + 1]);
		cout << ans << endl;
	}
	return 0;
}
