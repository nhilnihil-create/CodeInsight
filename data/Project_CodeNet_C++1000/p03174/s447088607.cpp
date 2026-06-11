#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int dp[22][(1<<22)];
int compat[22][22];
int solve(int compat[][22],int i,int womenSubset,int N){
    if(i==N+1){
        if(womenSubset == 0)
            return 1;
        return 0;
        }
        if(dp[i][womenSubset] != -1){return dp[i][womenSubset];}
        long ans=0;
        for(int women=0;women<N;women++){
            int available = womenSubset & (1<<women) ? 1 : 0;
            if(available && compat[i][women+1]){
                ans = (ans + solve(compat, i+1, womenSubset^(1<<women), N))%1000000007;
            }

        }
        return dp[i][womenSubset] = ans;
}
int32_t main() {
    cin>>n;
    memset(compat,0,sizeof compat);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>compat[i][j];
        }
    }
    memset(dp,-1,sizeof dp);
    cout<<solve(compat, 1, (1<<n)-1, n);
}
