#include <bits/stdc++.h>
using namespace std;
#define ll int
ll mod=1e9+7;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin>>n;
    ll dp[n+1][(1<<n)]={},x[n];
    for(ll i=0;i<(1<<n);i++) dp[0][i]=0;
    dp[0][0]=1;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<(1<<n);j++) dp[i+1][j]=0;
        for(ll j=0;j<n;j++){
            cin>>x[j];
            if(x[j]){
                ll p=((1<<n)-1)-(1<<j);
                for(ll k=p;k>0;k=(k-1)&p){
                    dp[i+1][k+(1<<j)]+=dp[i][k];
                    dp[i+1][k+(1<<j)]%=mod;
                }
                dp[i+1][(1<<j)]+=dp[i][0];
                dp[i+1][(1<<j)]%=mod;
            }
        }
        for(ll j=0;j<(1<<n);j++) dp[i+1][j]+=dp[i][j];
    }
    cout<<dp[n][(1<<n)-1];
}
