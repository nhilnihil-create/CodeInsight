#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define endl            "\n"
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zerbefone(x)    __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define Pi              acos(-1.0)
#define precise(x,y)    fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	FIO;

	int tt = 1;
	// cin >> tt;
	while (tt--)
	{
		string s, t;
		cin >> s >> t;
		int n = s.length(), m = t.length();
		int dp[n + 1][m + 1];
		int choice[n + 1][m + 1];
		memset(dp, 0, sizeof(dp));
		memset(choice, 0, sizeof(choice));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				dp[i][j] = dp[i - 1][j];
				choice[i][j] = 1;
				if (dp[i][j - 1] > dp[i][j])
				{
					dp[i][j] = dp[i][j - 1];
					choice[i][j] = 2;
				}
				if (s[i - 1] == t[j - 1])
				{
					if (dp[i - 1][j - 1] + 1 > dp[i][j])
					{
						dp[i][j] = dp[i - 1][j - 1] + 1;
						choice[i][j] = 3;
					}
				}
			}
		}
		string ans = "";
		int row = n, col = m;
		while (row && col)
		{
			if (choice[row][col] == 1)
			{
				row--;
			}
			else if (choice[row][col] == 2)
			{
				col--;
			}
			else
			{
				ans += s[row - 1];
				row--;
				col--;
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
	return 0;
}