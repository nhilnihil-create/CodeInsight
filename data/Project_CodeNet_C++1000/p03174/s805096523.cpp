#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 22;
const ll mod = 1e9 + 7;
int n, dp[N][1 << N], a[N][N];

int solve(int m, int w)
{
	if (m == n)
	{
		if (w == 0)
			return 1;
		return 0;
	}
	if (dp[m][w] != -1)
		return dp[m][w];
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		bool okay = ((((1 << i) & w) == 0) ? 0 : 1);
		if (okay && a[m][i])
			ans = (ans + solve(m + 1, (1 << i) ^ w)) % mod;
	}
	return dp[m][w] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, ((1 << n) - 1));

	return 0;
}