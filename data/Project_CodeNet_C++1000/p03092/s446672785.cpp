#include <bits/stdc++.h>

const int MAXN = 5010;
typedef long long LL;
int A[MAXN], va, vb, n;
LL dp[MAXN][MAXN];
void getmin(LL & x, const LL y) { x > y ? x = y : 0; }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> va >> vb;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	memset(dp, 0x3f, sizeof dp);
	**dp = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (j > A[i]) {
				getmin(dp[i][j], dp[i - 1][j] + vb);
			} else {
				getmin(dp[i][A[i]], dp[i - 1][j]);
				getmin(dp[i][j], dp[i - 1][j] + va);
			}
		}
	}
	std::cout << *std::min_element(dp[n], dp[n] + n + 1) << std::endl;
	return 0;
}
