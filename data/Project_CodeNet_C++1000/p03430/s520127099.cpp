#include<bits/stdc++.h>
using namespace std;

const int MAXN = 310;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch=='-') f=-1;
	for(; isdigit(ch); ch = getchar()) x = (x*10)+(ch^48);
	return x * f;
}

char s[310];
int dp[MAXN][MAXN][MAXN], K, n, ans;

inline void chkmax(int &cur, int val) {
	if(val > cur) cur = val;
}

int main() {

	scanf("%s", s+1);
	K = read();
	n = strlen(s+1);
	if(n == 1) {
		printf("1\n");
		return 0;
	}
	int i, j, k, d;
	//dp[1][n][0] = s[1] == s[n] ? 2 : 0;
	//dp[1][n][1] = 2;
	dp[0][n+1][0] = 0;
	for(d = n+1; d > 1; d--) 
		for(i = 0; i+d <= n+1; i++) {
			j = i+d;
			for(k = 0; k <= K; k++) {
				chkmax(dp[i][j-1][k], dp[i][j][k]);
				chkmax(dp[i+1][j][k], dp[i][j][k]);
				if(i + 1 != j-1) {
					chkmax(dp[i+1][j-1][k], dp[i][j][k]+(s[i+1] == s[j-1] ? 2 : 0));
					chkmax(dp[i+1][j-1][k+1], dp[i][j][k]+2);
				}
				else chkmax(dp[i+1][j-1][k], dp[i][j][k]+1);
				chkmax(ans, dp[i][j][k]);
			}
		}
	for(i = 1; i < n; i++) 
		for(k = 0; k <= K; k++) 
			chkmax(ans, dp[i][i+1][k]);
	for(i = 1; i <= n; i++)
		for(k = 0; k <= K; k++)
			chkmax(ans, dp[i][i][k]);
	printf("%d\n", ans);
	return 0;
}
