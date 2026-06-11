#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
 
char s[302];
int dp[302][302][301];
 
int main(){
	int k;
	scanf("%s%d", s + 1, &k);
	int n = strlen(s + 1);
	f(i, 1, n + 1)for (int j = n; j > 0; --j)f(w, 0, k + 1){
		if (s[i] == s[j])dp[i][j][w] = 1 + dp[i - 1][j + 1][w];
		else {
			dp[i][j][w] = max(dp[i - 1][j][w], dp[i][j + 1][w]);
			if (w)dp[i][j][w] = max(dp[i][j][w], 1 + dp[i - 1][j + 1][w - 1]);
		}
	}
	int an = 1;
	f(i, 1, n){
		int nv = dp[i][i + 1][k];
		an = max(an, nv << 1);
	}
	f(i, 1, n - 1){
		int nv = dp[i][i + 2][k];
		an = max(an, nv << 1 | 1);
	}
	printf("%d\n", an);
}