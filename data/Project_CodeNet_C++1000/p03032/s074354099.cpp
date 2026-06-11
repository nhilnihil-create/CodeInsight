#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long;
using P = pair<int, int>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;

int dp[55][55][105];
int main() {
    int n, K;
    cin >> n >> K;
    vector<int>v(n);
    rep(i, n)cin >> v[i];
    rep(i, 55)rep(j, 55)rep(k, 105)dp[i][j][k] = -INF;
    dp[0][n][0] = 0;
    rep(i, n)for (int j = n; j > 0; j--)rep(k, K) {
        if (i  >= j)break;
        if (dp[i][j][k] == -INF)continue;
        dp[i + 1][j][k + 2] = max(dp[i + 1][j][k + 2], dp[i][j][k]);
        dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + v[i]);
        dp[i][j - 1][k + 2] = max(dp[i][j - 1][k + 2], dp[i][j][k]);
        dp[i][j - 1][k + 1] = max(dp[i][j - 1][k + 1], dp[i][j][k] + v[j - 1]);

    }
    int ans = 0;
    rep(i, 55)rep(j, 55)rep(k,K+1) {
        ans = max(ans, dp[i][j][k]);
    }
    cout << ans << endl;
    return 0;
}