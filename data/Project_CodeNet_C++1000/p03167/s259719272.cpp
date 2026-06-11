#include <bits/stdc++.h>
using namespace std;
char grid[5001][5001];
long long mod=1e9+7;
int soln(int n,int m){
    int dp[n][m];memset(dp,0,sizeof(dp));
    dp[n-1][m-1]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1&&j==m-1)continue;
            else if(grid[i][j]=='#')dp[i][j]=0;
            else dp[i][j]=(((n-1-i>0)?dp[i+1][j]:0)+((m-1-j>0)?dp[i][j+1]:0))%mod;
        }
    }
    return dp[0][0];
}
int main() {
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<soln(n,m);
}
