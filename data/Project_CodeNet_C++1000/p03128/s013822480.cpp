#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3e5+5;
ll n,m,a[10];
ll cost[]={0,2,5,5,4,5,6,3,7,6};
ll dp[10005];
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(ll i=0;i<m;i++)cin>>a[i];
    sort(a,a+m);
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(ll i=0;i<n;i++){
        if(dp[i]==-1)continue;
        for(ll j=0;j<m;j++){
            if(i+cost[a[j]]<=n){
                dp[i+cost[a[j]]]=max(dp[i+cost[a[j]]],dp[i]+1);
            }
        }
    }
    string ans="";
    ll k=n;
    while(k){
        for(ll i=m-1;i>=0;i--){
            if(k-cost[a[i]]>=0 && dp[k-cost[a[i]]]==dp[k]-1){
                ans+=('0'+a[i]);
                k-=cost[a[i]];
                break;
            }
        }
    }
    cout<<ans;
}

