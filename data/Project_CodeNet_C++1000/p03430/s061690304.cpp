#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int dp[2][N][N];
char s[N];
int dfs(int l, int r, int dp[N][N]) {
	int &res = dp[l][r];
	if (dp[l][r] != -1) return dp[l][r];
	if (l > r) return res = 0;
	res = 0;
	if (s[l] == s[r]) res = dfs(l + 1, r - 1, dp) + (l == r ? 1 : 2);
	res = max(res, dfs(l + 1, r, dp));
	res = max(res, dfs(l, r - 1, dp));
	return res;
}
int dfs2(int l, int r, int dp[N][N], int fr[N][N]) {
	int &res = dp[l][r];
	if (dp[l][r] != -1) return dp[l][r];
	if (l > r) return res = 0;
	res = 0;
	if (s[l] == s[r]) res = dfs2(l + 1, r - 1, dp, fr) + (l == r ? 1 : 2);
	res = max(res, fr[l + 1][r - 1] + (l == r ? 1 : 2));
	res = max(res, dfs2(l + 1, r, dp, fr));
	res = max(res, dfs2(l, r - 1, dp, fr));
	return res;
}
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1), k;
	scanf("%d", &k);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; ++ i) {
		for (int j = i; j <= n; ++ j) {
			dfs(i, j, dp[0]);
		}
	}
	int cur = 0;
	int ans = dp[cur][1][n];
	for (int i = 1; i <= k; ++ i) {
		cur ^= 1;
		memset(dp[cur], -1, sizeof(dp[cur]));
		for (int i = 1; i <= n; ++ i) {
			for (int j = i + 1; j <= n; ++ j) {
				dfs2(i, j, dp[cur], dp[cur ^ 1]);
			}
		}
		ans = max(ans, dp[cur][1][n]);
	}
	printf("%d\n", ans);
}

