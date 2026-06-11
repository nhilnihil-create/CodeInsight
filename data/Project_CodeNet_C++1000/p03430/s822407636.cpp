#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>

const int N = 3e2 + 10;

int len, k;
int dp[N][N][N];
char s[N];

int dfs(int L, int R, int p) {
	if (dp[L][R][p] != -1) return dp[L][R][p];
	if (L > R) return dp[L][R][p] = 0;
	if (L == R) return dp[L][R][p] = 1;
	dp[L][R][p] = std::max(dfs(L + 1, R, p), dfs(L, R - 1, p));
	if (s[L] == s[R]) dp[L][R][p] = std::max(dp[L][R][p], dfs(L + 1, R - 1, p) + 2);
	if (p) dp[L][R][p] = std::max(dp[L][R][p], dfs(L + 1, R - 1, p - 1) + 2);
	return dp[L][R][p];
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf(" %s%d", s + 1, &k), len = strlen(s + 1);
	printf("%d\n", dfs(1, len, k));
	return 0;
}