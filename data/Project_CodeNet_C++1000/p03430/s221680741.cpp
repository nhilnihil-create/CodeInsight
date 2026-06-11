#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; i++)

using namespace std;

const int N = 310;

void chkmax(int &x, int y) { x = x < y ? y : x; }

int dp[N][N][N];
char S[N];
int n, k;

int main() {

	scanf("%s%d", S + 1, &k);
	n = strlen(S + 1);
	dp[0][0][0] = 0;
	
	For(i, 0, n) For(j, 0, n) For(u, 0, k) {
		if (i) chkmax(dp[i][j][u], dp[i - 1][j][u]);
		if (j) chkmax(dp[i][j][u], dp[i][j - 1][u]);
		if (i && j) {
			int nu = u - (S[n + 1 - j] != S[i]);
			if (nu >= 0) chkmax(dp[i][j][u], dp[i - 1][j - 1][nu] + 1);
		}
	}

	int ans = 0;
	For(i, 0, n) chkmax(ans, dp[i][n - i][k] * 2);
	For(i, 0, n - 1) chkmax(ans, dp[i][n - i - 1][k] * 2 + 1);
	printf("%d\n", ans);

	return 0;
}