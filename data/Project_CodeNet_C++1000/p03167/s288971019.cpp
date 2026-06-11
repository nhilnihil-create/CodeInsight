// Author: Sayantanu
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
const int mod = 1e9 + 7;

int main() {
    int n,m;
    cin>>n>>m;
    int dp[n][m];
    memset(dp,-1,sizeof(dp));
    dp[n-1][m-1] = 1;
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0  ; j < m; j++){
            char c;
            cin>>c;
            if(c=='#')dp[i][j] = 0;
        }

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(dp[i][j]==-1){
                if((i+1)<n)dp[i][j] = dp[i+1][j];
                if((j+1)<m)dp[i][j] = (max(dp[i][j],0) + dp[i][j+1])%mod;
                if(dp[i][j]==-1)
                    dp[i][j] = 0;
            }
        }
    }


    cout<<dp[0][0]<<endl;
    return 0;
}