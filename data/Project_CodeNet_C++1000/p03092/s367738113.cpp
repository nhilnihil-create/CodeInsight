#include <bits/stdc++.h>

typedef long long LL;
const int N = 5005;
const LL inf = 0x3f3f3f3f3f3f3f3f;

int n, a, b;
LL dp[N][N], ans = inf;

void down(LL &x, LL y) { x = std::min(x, y); }
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::memset(dp, 0x3f, sizeof dp), std::cin >> n >> a >> b;
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		int x; std::cin >> x;
		for (int j = 0; j <= n; ++j) if (dp[i][j] < inf) {
			if (x < j)
				down(dp[i + 1][j], dp[i][j] + b);
			else
				down(dp[i + 1][x], dp[i][j]),
				down(dp[i + 1][j], dp[i][j] + a);
		}
	}
	for (int i = 0; i <= n; ++i) down(ans, dp[n][i]);
	std::cout << ans << '\n';
	return 0;
}