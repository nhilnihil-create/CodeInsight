#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int g[2][n];
    for(int i=0; i<2; i++)
    for(int j=0; j<n; j++){
        cin >> g[i][j];
    }
    int dp[3][n+1];
    for(int i=0; i<=2; i++)
        for(int j=0; j<=n; j++)
        dp[i][j]=0;
    for(int i=1; i<=2; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = max(dp[i][j-1],dp[i-1][j])+ g[i-1][j-1];
                //cout << dp[i][j] << " ";
        }
       // cout << endl;
    }
    cout << dp[2][n];
}
