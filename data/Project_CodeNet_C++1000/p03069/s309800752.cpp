#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

signed main(void)
{
	int n, m, tmp;
	string s;
	ll cnt, ans; 
	cin >> n >> s;
	vector<ll> w(n + 1, 0), b(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		if (s[i - 1]  == '#')
			b[i]++;
		if (s[i - 1] == '.')
			w[i]++;
	}
	rep(i, n)
	{
		b[i + 1] += b[i];
		w[i + 1] += w[i];
	}
	ans = 200010;
	rep(i, n + 1)
	{
		cnt = b[i] + (w[n] - w[i]);
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
