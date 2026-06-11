#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3005,mod=1e9+7;
ll n,ans,dp[2][N];
string s;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>s;
    dp[1][1]=1;
    for(ll len=2;len<=n;len++){
        for(ll i=1;i<=len-1;i++)dp[1-(len&1)][i]+=dp[1-(len&1)][i-1],dp[1-(len&1)][i]%=mod;
        for(ll i=1;i<=len;i++)dp[len%2][i]=0;
        for(ll l,r,i=1;i<=len;i++){
            if(s[len-2]=='<')l=1,r=i-1;
            else l=i,r=len-1;
            if(l>r)continue;
            dp[len%2][i]=dp[len%2][i]+dp[1-(len%2)][r];dp[len%2][i]%=mod;
            dp[len%2][i]=dp[len%2][i]-dp[1-(len%2)][l-1]+mod;
            dp[len%2][i]%=mod;
        }
    }
    for(ll i=1;i<=n;i++)ans+=dp[n%2][i],ans%=mod;
    cout<<ans;
}