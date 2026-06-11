#include<cstdio>
#include<cstring>
short dp[305][305][305];
char in[310];
void upd(short &x, short y) {
	if (x < y) x = y;
}
int main() {
	int n, k;
	scanf("%s%d", in+1, &k);
	n = strlen(in+1);
	for (int i = 1; i <= n; i++) for (int j = 0; j <= k; j++) dp[i][i][j] = 1;
	for (int d = 1; d <= n; d++) {
		for (int i = 1; i + d <= n; i++) {
			int j = i + d;
			for (int t = 0; t <= k; t++) {
				upd(dp[i][j][t], dp[i + 1][j][t]);
				upd(dp[i][j][t], dp[i][j - 1][t]);
			}
			if (in[i] == in[j]) {
				for (int t = 0; t <= k; t++) upd(dp[i][j][t], dp[i + 1][j - 1][t] + 2);
			}
			else {
				for (int t = 1; t <= k; t++) upd(dp[i][j][t], dp[i + 1][j - 1][t-1] + 2);
			}
		}
	}
	printf("%d\n", dp[1][n][k]);
	return 0;
}