#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    int n;
    cin >> n;
    vector<vector<int>>a(2,vector<int>(n));
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    int dp[2][n];
    dp[0][0]=a[0][0];
    dp[1][0]=a[0][0]+a[1][0];
    for(int i=1;i<n;i++){
        dp[0][i]=dp[0][i-1]+a[0][i];
        dp[1][i]=max(dp[1][i-1]+a[1][i],dp[0][i]+a[1][i]);
    }
    cout << dp[1][n-1] << endl;
}