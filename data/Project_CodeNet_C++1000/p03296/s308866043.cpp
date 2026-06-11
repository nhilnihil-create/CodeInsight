#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n;
	cin >> n;
	int a[n];
	int cnt, ans;
	rep(i, n) cin >> a[i];
	ans = 0;
	cnt = 1;
	for(int i = 0; i < n; i++)
	{
		if (a[i] != a[i + 1])
		{
			ans += cnt / 2;
			cnt = 1;
		}
		else
			cnt++;
	}
	cout << ans << endl;
	return 0;
}
