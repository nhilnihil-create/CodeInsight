#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 22, mod = 1e9 + 7;
int N, a[MAXN][MAXN];
ll dp[MAXN][1 << MAXN];

ll rec(int m, int w)
{
	if (m == N)
	{
		if (w == 0)
			return 1;
		return 0;
	}
	if (dp[m][w] != -1)
		return dp[m][w];
	ll tot = 0;
	for (int i = 0; i < N; i++)
	{
		int woman = 1 << i;
		bool available = ((woman & w) != 0);
		if (available && a[m][i])
			tot = (tot + rec(m + 1, w ^ woman)) % mod;
	}
	return dp[m][w] = tot;
}

int main()
{
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> a[i][j];
	memset(dp, -1, sizeof(dp));
	ll ans = rec(0, (1 << N) - 1);
	cout << ans;

	return 0;
}