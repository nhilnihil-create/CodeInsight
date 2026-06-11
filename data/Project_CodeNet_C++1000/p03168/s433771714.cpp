#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define itn int
#define rep(i,n) for(int i = 0;i < n;i++)

long double dp[3000][3000];

int main(){
    int n;
    cin >> n;
    long double p[n];
    for(int i = 0;i < n;i++)cin >> p[i];
    
    dp[0][0] = 1;
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= n;j++){
            if(j > 0)dp[i+1][j] = dp[i][j] * (1 - p[i]) + dp[i][j-1] * p[i];
            else dp[i+1][j] = dp[i][j] * (1 - p[i]);
        }
    }
    
    long double ans = 0;
    for(int i = (n + 1) / 2;i <= n;i++){
        ans += dp[n][i];
    }
    cout << setprecision(12) << ans << endl;
}
