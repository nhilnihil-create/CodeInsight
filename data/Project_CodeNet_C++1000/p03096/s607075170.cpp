#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
const int MOD = 1000000007;
int N,C[MAXN],sum[MAXN];
int dp[MAXN][2];
int inc(int a,int b) { return a + b >= MOD ? a + b - MOD : a + b; }
int mul(int a,int b) { return 1LL * a * b % MOD; }
int main() {
	scanf("%d",&N);for (int i=1;i<=N;i++)scanf("%d",&C[i]);
    dp[0][0] = 1;
    for(int i = 1 ; i <= N ; ++i) {
        dp[i][0] = inc(dp[i - 1][1],dp[i - 1][0]);
        if(C[i] != C[i - 1]) {
            dp[i][1] = sum[C[i]];
            sum[C[i]] = inc(sum[C[i]],dp[i][0]);
        }
    }
    printf("%d\n",inc(dp[N][0],dp[N][1]));
	return 0;
}