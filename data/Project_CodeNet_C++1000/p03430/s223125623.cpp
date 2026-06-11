#include <cstdio>
char s[310];
int l, K;
int dp[2][310][310];
void upd(int &v, int x) {
	if (v < x) v = x;
}
int main() {
	scanf("%s%d", s, &K);
	for (l = 0; s[l]; l++) ;
	for (int i = 0; i < l; i++) {
		dp[0][i][i+1] = 1;
	}
	for (int i = 2; i <= l; i++) {
		for (int j = 0; j < l - i + 1; j++) {
			if (s[j] == s[j+i-1]) {
				upd(dp[0][j][j+i], dp[0][j+1][j+i-1] + 2);
			}
			upd(dp[0][j][j+i], dp[0][j+1][j+i]);
			upd(dp[0][j][j+i], dp[0][j][j+i-1]);
		}
	}
	int y = 0, z = 1;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j <= l; j++) {
			for (int k = 0; k <= l; k++) {
				dp[z][j][k] = j + 1 == k;
			}
		}
		for (int j = 2; j <= l; j++) {
			for (int k = 0; k < l - j + 1; k++) {
				if (s[k] == s[k+j-1]) {
					upd(dp[z][k][k+j], dp[z][k+1][k+j-1] + 2);
				} else {
					upd(dp[z][k][k+j], dp[y][k+1][k+j-1] + 2);
				}
				upd(dp[z][k][k+j], dp[y][k][k+j]);
				upd(dp[z][k][k+j], dp[z][k+1][k+j]);
				upd(dp[z][k][k+j], dp[z][k][k+j-1]);
			}
		}
		y ^= 1;
		z ^= 1;
	}
	printf("%d\n", dp[y][0][l]);
	return 0;
}
