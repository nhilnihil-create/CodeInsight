#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, ans, cnt;
	string s;
	cin >> n >> s;
	int cnt_w[n], cnt_e[n];

	rep(i, n)
	{	
		cnt_w[i] = 0;
		cnt_e[i] = 0;
	}
	rep(i, n)
	{
		if (s[i] =='W')
			cnt_w[i]++;
		else if (s[i] == 'E')
			cnt_e[i]++;
	}
	rep(i, n - 1)
	{	
		cnt_e[i + 1] += cnt_e[i];
		cnt_w[i + 1] += cnt_w[i];
	}
	ans = (int)1e9;
	rep(i, n)
	{
		cnt = 0;
		cnt += cnt_e[n - 1] - cnt_e[i];
		if (i - 1 >= 0)
			cnt += cnt_w[i - 1];
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
