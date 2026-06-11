#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int A[3][101];
    for(int i = 1; i <= 2; ++i){
        for(int j = 1; j <= n; ++j){
            cin>>A[i][j];
        }
    }
    
    int dp[3][101] = {};
    for(int i = 1; i <= 2; ++i){
        for(int j = 1; j <= n; ++j){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + A[i][j];
        }
    }
    
    cout << dp[2][n]<< endl;
    return 0;
}
