#include<bits/stdc++.h>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;

const int maxn = 5500;
ll dp[maxn][maxn];
int n, A, B, p[maxn], f[maxn];
// A: right, B: left

void upd(ll& x, ll y) { x = min(x, y); }
int main() {
    memset(dp, 0x3f, sizeof dp);
    scanf("%d%d%d", &n, &A, &B);
    rep(i, n) scanf("%d", &p[i]), f[p[i]] = i;
    
    memset(dp[0], 0, sizeof(dp[0]));
    for(int i = 0; i < n; ++i) {    
        for(int j = 1; j <= n; ++j) dp[i][j] = min(dp[i][j-1], dp[i][j]);
        for(int j = 1; j <= n; ++j) { // [0, j)
            if(j == f[i+1]) upd(dp[i+1][j], dp[i][j]);
            else if(j > f[i+1]) upd(dp[i+1][j], dp[i][j] + A);
            else if(j < f[i+1]) upd(dp[i+1][j], dp[i][j] + B);
        }
    }
    for(int i = 1; i <= n; ++i) dp[n][i] = min(dp[n][i-1], dp[n][i]);
    printf("%lld\n", dp[n][n]);

    return 0;
}