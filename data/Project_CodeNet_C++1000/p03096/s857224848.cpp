#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;
const ll mod=1e9+7;

ll cl[200010],dp[200010];
vector<ll> last(200010,-1);

int main(){
    ll n;cin>>n;
    dp[0]=1;
    rep(i,0,n){
        ll a;cin>>a;
        if(last[a]==-1){
            dp[i+1]=dp[i];
            last[a]=i;
            cl[a]+=dp[i];
            cl[a]%=mod;
        }
        else if(last[a]==i-1){
            dp[i+1]=dp[i];
            last[a]=i;
        }
        else{
            dp[i+1]=dp[i]+cl[a];
            last[a]=i;
            cl[a]+=dp[i];
            cl[a]%=mod;
        }
        dp[i+1]%=mod;
    }
    cout<<dp[n]<<endl;
}
    







