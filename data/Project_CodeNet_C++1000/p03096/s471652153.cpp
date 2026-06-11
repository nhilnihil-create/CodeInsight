#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod=1e9+7,N=2e5+5;
ll c[N],dp[N],sum[N];
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n;cin>>n;
    for(ll i=1;i<=n;i++)cin>>c[i];
    sum[c[1]]=dp[1]=1;
    for(ll i=2;i<=n;i++){
        if(c[i-1]!=c[i]){
            sum[c[i]]+=dp[i-1];
            sum[c[i]]%=mod;
        }
        dp[i]=sum[c[i]];
    }
    cout<<dp[n];
}


