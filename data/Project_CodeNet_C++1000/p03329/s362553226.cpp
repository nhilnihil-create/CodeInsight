#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

const ll INF=1e9;

int main(){
    ll n;
    cin>>n;
    vector<ll> dp(n+1,INF);
    dp[0]=0;
    for(ll i=1;i<=n;i++){
        dp[i]=min(dp[i],dp[i-1]+1);
        for(ll j=6;j<=i;j*=6) dp[i]=min(dp[i],dp[i-j]+1);
        for(ll j=9;j<=i;j*=9) dp[i]=min(dp[i],dp[i-j]+1);
    }
    cout<<dp[n]<<endl;
    return 0;
}