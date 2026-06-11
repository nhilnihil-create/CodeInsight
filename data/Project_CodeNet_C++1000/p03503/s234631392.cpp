#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, ans, sum, cnt; cin >> n;
	int f[n][10];
	int p[n][11];

	rep(i, n) rep(j, 10) cin >> f[i][j];
	rep(i, n) rep(j, 11) cin >> p[i][j];
	ans = (int) -1e9;
	for(int bit = 1; bit < (1 << 10); bit++)
	{
		int plan[10];
		for(int i = 0; i < 10; i++)
		{
			if (bit & (1 << i))
			{
				plan[i] = 1;
			}
			else
				plan[i] = 0;
		}
		sum = 0;
		rep(j, n)
		{
			cnt = 0;
			rep(i, 10)
			{
				if (plan[i] & f[j][i])
					cnt++; 
			}
			sum += p[j][cnt];
		}
		ans = max(ans, sum);
	}
	cout <<  ans << endl;
	return 0;
}
