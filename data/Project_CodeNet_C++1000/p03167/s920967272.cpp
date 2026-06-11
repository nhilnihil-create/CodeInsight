#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int h, w; cin >> h >> w;
	vector<vector<int>>dp(h, vector<int>(w, 0));
	vector<string>mat(h);
	for (auto &it : mat)
		cin >> it;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (mat[i][j] != '#')
			{
				if (i == 0 && j == 0)
					dp[i][j] = 1;
				else if (j == 0)
					dp[i][j] = dp[i - 1][j];
				else if (i == 0)
					dp[i][j] = dp[i][j - 1];
				else
					dp[i][j] = (dp[i - 1][j] + 0ll + dp[i][j - 1]) % MOD;
			}
		}
	}
	cout << dp[h - 1][w - 1];

	return 0;
}