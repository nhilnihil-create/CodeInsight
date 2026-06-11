#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

signed main(void)
{
	int n;
	cin >> n;
	int a[n], b[n];
	ll ans;
	rep(i, n) cin >> a[i];
	if (a[0] != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	rep(i, n - 1)
	{
		if (a[i + 1] - a[i] > 1) 
		{
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = n - 1; i >= 0; i--)
		b[i] = i - a[i];
	ans = 0;
	int tmp = -1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (tmp != b[i])
			ans += i - b[i];
		tmp = b[i];
	}
	cout << ans << endl;
	return 0;
}
