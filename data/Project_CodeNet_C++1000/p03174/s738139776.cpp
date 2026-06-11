#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[22][(1<<22)];
ll mod=1e9+7;
ll solve(vector<vector<ll>> &v,int i,int womenset,int n){
    if(i==n+1){
        if(womenset==0){
            return 1;
        }
        return 0;
    }
    if(dp[i][womenset]!=-1){
        return dp[i][womenset];
    }
    ll ans=0;
    for(ll women=0;women<n;women++){
       bool avail=(((womenset) & (1<<women))==0) ? 0:1;
       if(avail && v[i][women+1]){
           ans=(ans+solve(v,i+1,(womenset^(1<<women)),n));
           ans=ans%mod;
       }
    }
    return dp[i][womenset]=ans;
}
int main(){
    ll n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    vector<vector<ll> >v(n+1,vector<ll> (n+1));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin>>v[i][j];
        }
    }

    cout<<solve(v,1,((1<<n)-1),n);

    return 0;
}
