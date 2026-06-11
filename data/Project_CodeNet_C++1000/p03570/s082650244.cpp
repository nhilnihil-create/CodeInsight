#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const ll N=2e5+5,inf=1e9;
ll dp[N],prfx[N],best[1<<26];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;cin>>s;
    ll n=s.size();
    for(ll i=0;i<n;i++)prfx[i+1]=prfx[i]^(1<<(s[i]-'a'));
    for(ll i=0;i<(1<<26);i++)best[i]=inf;
    dp[0]=best[prfx[0]]=0;
    for(ll i=1;i<=n;i++){
        dp[i]=inf;
        for(ll bit=-1;bit<26;bit++){
            ll cur = prfx[i];
            if(bit>=0)cur^=(1ll<<bit);
            dp[i]=min(dp[i] , best[cur]+1);
        }
        best[prfx[i]]=min(best[prfx[i]],dp[i]);
    }
    cout<<dp[n];
}