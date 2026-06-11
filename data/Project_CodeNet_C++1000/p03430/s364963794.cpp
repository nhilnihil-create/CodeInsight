#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 305;

string S;
int k;
int dp[Maxn][Maxn][Maxn];
int res;

int main()
{
	cin >> S;
	cin >> k;
	fill((int*)dp, (int*)dp + Maxn * Maxn * Maxn, -Inf);
	dp[0][int(S.length()) - 1][0] = 0;
	for (int i = 0; i < S.length(); i++)
		for (int j = int(S.length()) - 1; j >= 0; j--)
			for (int l = 0; l <= k; l++) if (dp[i][j][l] >= 0) {
				if (i == j) { res = max(res, dp[i][j][l] + 1); continue; }
				else if (i > j) { res = max(res, dp[i][j][l]); continue; }
				if (S[i] == S[j]) dp[i + 1][j - 1][l] = max(dp[i + 1][j - 1][l], dp[i][j][l] + 2);
				dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l]);
				dp[i][j - 1][l] = max(dp[i][j - 1][l], dp[i][j][l]);
				if (l + 1 <= k) dp[i + 1][j - 1][l + 1] = max(dp[i + 1][j - 1][l + 1], dp[i][j][l] + 2);
			}
	printf("%d\n", res);
	return 0;
}