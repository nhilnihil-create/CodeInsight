#include <bits/stdc++.h>
using namespace std;
const int maxn = 300 + 10;
int dp[maxn][maxn][maxn];
char s[maxn];
int n, k, ans;
int f(int i, int j, int k)
{
	if(i == 0 || j == n + 1) return 0;
	if(~dp[i][j][k]) return dp[i][j][k];
	int ret = max(f(i - 1, j, k), f(i, j + 1, k));
	if(s[i] == s[j]) ret = max(ret, f(i - 1, j + 1, k) + 1);
	else if(k > 0) ret = max(ret, f(i - 1, j + 1, k - 1) + 1);
	return dp[i][j][k] = ret;
}
int main()
{
	memset(dp, -1, sizeof dp);
	scanf("%s", s + 1);
	scanf("%d", &k);
	n = strlen(s + 1);
	for(int i = 1; i < n; ++i) ans = max(ans, f(i, i + 1, k) * 2);
	for(int i = 1; i <= n; ++i) ans = max(ans, f(i - 1, i + 1, k) * 2 + 1);
	printf("%d\n", ans);
	return 0;
}
	