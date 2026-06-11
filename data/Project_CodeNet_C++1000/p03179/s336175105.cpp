#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
                     
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
const ll mod = 1e9+7;
ll mult(ll a,ll b){return ((a%mod)*(b%mod))%mod;}

ll add(ll a,ll b){return ((a%mod)+(b%mod))%mod;}
ll sub(ll a,ll b){return ((a%mod)-(b%mod)+mod)%mod;} 
ll dp[3003][3003];
int solve(){
    ll n;string s;
    cin>>n;cin>>s;

    // memset(dp, -1, sizeof(dp));
    
    // cout<<"doje";
    for(int i=0;i<=n-1;++i){
        dp[0][i] = 1;
    }
    for(int pos=1;pos<n;++pos){
        if(s[pos-1]=='<'){
            ll ans = 0;
            for(int badacount=n-1; badacount >= 0; --badacount){
                ans =  add(ans, dp[pos-1][badacount+1]);
                // cout<<pos-1<<" "<<badacount+1<<" = "<<dp[pos-1][badacount+1]<<endl;
                dp[pos][badacount] = ans;
            }
        }
        else{
            ll ans = 0;
            for (int badacount = 0; badacount <= n - 1 && n - pos - badacount > 0; ++badacount){
                ans = add(ans, dp[pos - 1][badacount]);
                dp[pos][badacount] = ans;
            }
        }
    }
    ll ans = 0;
    for(int i=0;i<n;++i){
        ans = add(ans, dp[n-1][i]);
    }
    cout<<ans;
    return 0;
}
int main(){
    fast;
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}