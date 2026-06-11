#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <tuple>
template <typename T> constexpr T my_abs(const T &x) { return x < 0 ? -x : x; }
using ll = long long;
ll dp[5005][5005];
int main()
{
	// freopen("AGC032-D.in", "r", stdin);
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		for (int j = 0; j <= n; j++)
		{
			if (dp[i][j] >= 1e18)
				continue;
			if (x > j)
			{
				dp[i + 1][x] = std::min(dp[i + 1][x], dp[i][j]);
				dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j] + a);
			}
			else
				dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j] + b);
		}
	}
	ll ans = 1e18;
	for (int i = 0; i <= n; i++)
		ans = std::min(ans, dp[n][i]);
	printf("%lld\n", ans);
	return 0;
}
