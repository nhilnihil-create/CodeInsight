#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define f(i,x,n) for(int i=x;i<n;i++) 
#define all(c) c.begin(),c.end()
const int MOD = 1e9 + 7, N = 3e3 + 10;
const int LINF = LLONG_MAX;
double dp[N][N];
double C[N];
int n;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(10) << fixed ;
    memset(dp,0,sizeof(dp));
    cin >> n;
    f(i,0,n){
        cin >> C[i];
    }
    dp[0][0] = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= i;j++){
            dp[i+1][j+1] += dp[i][j]*C[i];
            dp[i+1][j] += dp[i][j]*(1 - C[i]);
        }
    }
    double ans = 0;
    for(int j = (n+1)/2;j <= n;j++){
        ans += dp[n][j];
    }
    cout << ans;
    return 0;
}
 