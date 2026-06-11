#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,k;
    cin>>n>>k;
    ll x[n],dp[k+1]={};
    dp[0]=1;
    for(ll &i:x) cin>>i;
    for(ll i=0;i<n;i++){
        ll pre[k+2]={};
        for(ll j=0;j<=k;j++) pre[j+1]=pre[j]+dp[j],pre[j+1]%=mod;
        for(ll j=k;j>=0;j--){
            dp[j]+=pre[j]-pre[max(j-x[i],0ll)];
            dp[j]=(dp[j]+mod)%mod;
        }
    }
    cout<<dp[k];
}
