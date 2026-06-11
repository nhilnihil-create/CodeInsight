#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, ans, cnt;
	cin >> n;
	int b[n + 1], w[n + 1];
	string s;

	cin >> s;
	for(int i = 0; i <= n; i++)
		b[i] = w[i] = 0;
	rep(i, n)
	{
		if (s[i] == '#')
			b[i + 1]++;
		else if (s[i] == '.')
			w[i + 1]++;
	}
	rep(i, n)
	{
		b[i + 1] += b[i];
		w[i + 1] += w[i];
	}
	ans = 1e9;
	rep(i, n + 1)
	{
		cnt = 0;
		cnt += b[i];
		cnt += w[n] - w[i];
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
