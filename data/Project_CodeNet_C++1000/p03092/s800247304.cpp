#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long MAXN =5e3+5;
long long dp[MAXN][MAXN];
long long pos[MAXN];
long long p[MAXN];
long long mindp[MAXN];
int main(){
    long long n,a,b;
    cin>>n>>a>>b;
    for(long long i=1;i<=n;i++){
        cin>>p[i];
        pos[p[i]] = i;
    }
    for(long long i=1;i<=n;i++){
        for(long long j=0;j<=n;j++){
            dp[i][j] = 1e18;
        }
    }
    dp[0][0] = 0; 
    for(long long i=1;i<=n;i++){
        for(long long j=0;j<=n;j++){
           
            if(j==pos[i]){
                dp[i][j] = dp[i-1][j-1];
                continue;
            }
            long long cost;
            if(pos[i]<j){
                cost = a;
            }else{
                cost = b;
            }
            if(j){
                dp[i][j] = min(dp[i][j],dp[i][j-1]);
               
            }
             dp[i][j] = min(dp[i][j],dp[i-1][j]+(cost));
            // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    cout<<dp[n][n]<<endl;
}