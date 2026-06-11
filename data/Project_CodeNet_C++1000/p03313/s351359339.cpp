#include <bits/stdc++.h>

using namespace std;

const int maxk = 19, maxn = 263*1000, INF = 1*1000*1000*1000+10;
int a, n, mx[maxn][maxk][2], dp[maxn], g[maxn][maxk], h[maxn];
vector<int> tmp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < (1 << n); i++)
	{
		cin >> a;
		h[i] = a;
		mx[i][0][0] = a;
		mx[i][0][1] = -INF;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j + (1 << i) <= (1 << n); j++)
		{
			tmp.clear();
			tmp.push_back(mx[j][i - 1][0]);
			tmp.push_back(mx[j][i - 1][1]);
			tmp.push_back(mx[j + (1 << (i - 1))][i - 1][0]);
			tmp.push_back(mx[j + (1 << (i - 1))][i - 1][1]);
			sort(tmp.begin(), tmp.end());
			mx[j][i][0] = tmp[3];
			mx[j][i][1] = tmp[2];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (1 << n); j++)
		{
			if (j & (1 << i))
			{
				a = (j >> (i + 1)) << (i + 1);
				dp[j] = max(dp[j], mx[a][i][0] + mx[a][i][1]);
				dp[j] = max(dp[j], mx[a][0][0] + mx[a | (1 << i)][0][0]);
				dp[j] = max(dp[j], h[j] + h[j ^ (1 << i)]);
				h[j] = max(h[j], h[j ^ (1 << i)]);
				g[j][i] = mx[a][i][0];
				for (int k = 0; k < i; k++)
				{
					if (j & (1 << k))
					{
						dp[j] = max(dp[j], g[j][k] + g[j ^ (1 << i)][k]);
						g[j][k] = max(g[j][k], g[j ^ (1 << i)][k]);
					}
				}
			}
		}
	}
	for (int i = 1; i < (1 << n); i++)
		cout << dp[i] << endl;
	return 0;
}