#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3010;
using ll = long long;

int N;
double p[MAXN];
// dp[i][j]: 前i个硬币j个头朝上的概率
double dp[MAXN][MAXN];

int main() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> p[i];
    }

    dp[0][0] = 1; 
    for(int i=1; i<=N; i++) {
        for(int j=0; j<=i; j++) {
            if(j) dp[i][j] += dp[i-1][j-1]*p[i];
            dp[i][j] += dp[i-1][j] * (1-p[i]);
        }
    }
    /*
    for(int i=1; i<=N; i++) {
        dp[i][0] = dp[i-1][0] * (1-p[i]);
        dp[0][i] = 0.0;
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=i; j++) {
            dp[i][j] = dp[i-1][j]*(1-p[i]) + dp[i-1][j-1]*p[i];
        }
    }
    */
    double ans = 0.0;
    for(int i=(N+1)/2; i<=N; i++) {
        ans += dp[N][i];
    }
    cout <<setprecision(10) << ans << endl;
    return 0;
}