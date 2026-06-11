#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;

char str[MAXN];
int n, k;
int dp[MAXN][MAXN][MAXN];

int dfs(int L, int R, int k)
{
	if (k < 0) return -1e8;
	if (L > R) return 0;
	if (L == R) return 1;
	if (dp[L][R][k] != -1) return dp[L][R][k];
	dp[L][R][k] = max(dfs(L+1, R, k), dfs(L, R-1, k));
	dp[L][R][k] = max(dp[L][R][k], dfs(L+1, R-1, k-(str[L] != str[R]))+2);
	return dp[L][R][k];
}

int main()
{
	memset(dp, -1, sizeof dp);
	scanf("%s", str+1), n = strlen(str+1);
	scanf("%d", &k);
	cout << dfs(1, n, k) << endl;
	return 0;
}
