#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
const int INF = -(1e9+123);
int a[N],b[N],c[N],dp[N][3];
int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    cout << endl;
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
    for(int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i-1][1],dp[i-1][2])+a[i];
        dp[i][1] = max(dp[i-1][0],dp[i-1][2])+b[i];
        dp[i][2] = max(dp[i-1][0],dp[i-1][1])+c[i];
        //cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    }
    cout << max(max(dp[n][0],dp[n][1]),dp[n][2]);
}