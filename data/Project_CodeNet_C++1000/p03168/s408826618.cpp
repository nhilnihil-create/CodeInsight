#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    double p[n];
    for(int i=1;i<=n;i++) cin>>p[i];
    double dp[n+1][n+1];
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            dp[i][j] = dp[i-1][j]*(1-p[i]) + dp[i-1][j-1]*p[i];
        }
    }
    double ans=0.0;
    for(int j=n/2+1;j<=n;j++){
        ans += dp[n][j];
    }

    cout << fixed << setprecision(10) << ans;
}