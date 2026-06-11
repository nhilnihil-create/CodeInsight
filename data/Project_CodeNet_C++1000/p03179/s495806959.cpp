#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,a,b) for(ll i=b-1;i>=a;i--)
const ll maxn=3e3+5, mod=1e9+7;
ll n,dp[maxn][maxn];
string s;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>s;
    dp[1][1]=1;
    rep(i,2,n+1)
        if(s[i-2]=='<')
            rep(j,1,i+1)
                dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%mod;
        else
            per(j,1,i+1)
                dp[i][j]=(dp[i-1][j]+dp[i][j+1])%mod;
    ll ans=0; rep(i,1,n+1) (ans+=dp[n][i])%=mod;
    cout<<ans<<"\n";

}
