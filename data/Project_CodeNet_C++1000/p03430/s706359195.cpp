#include<bits/stdc++.h>
using namespace std;

const int maxn = 305;
int f[maxn][maxn][maxn], g[maxn][maxn], n, K, ans;
char s[maxn];

int main() {
	scanf("%s%d", s + 1, &K);
	n = strlen(s + 1);
	for (int l=n; l>=1; l--) {
		f[l][l][0] = 1;
		for (int r=l+1; r<=n; r++) 
			for (int k=0; k<=K; k++) {
				f[l][r][k] = max(f[l+1][r][k], f[l][r-1][k]);
				if (s[l] == s[r]) f[l][r][k] = max(f[l][r][k], f[l+1][r-1][k] + 2);
				else if (k) f[l][r][k] = max(f[l][r][k], f[l+1][r-1][k-1] + 2);
			}
	}
	for (int k=0; k<=K; k++) ans = max(ans, f[1][n][k]);
	printf("%d", ans);
	return 0;
}