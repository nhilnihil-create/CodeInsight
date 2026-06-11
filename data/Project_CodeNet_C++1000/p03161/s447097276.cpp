#include<bits/stdc++.h>
#include<algorithm>
#include<set>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stack>
using namespace std;
typedef long long int ll;
const int MOD=1e9+7;
// power function with a^b 
ll power(ll a, ll b){
    ll ans=1;
    while(b>0){
        if(b%2!=0)
        ans=ans*a;

        b/=2;
        a=a*a;
    }
    return ans;
}
// power function with modulo i.e (a^b)%mod
ll powermod(ll a,ll b, ll mod){
    ll ans=1;
    a=a%mod;
    if(a==0) return 0;
    while(b>0){
        if(b%2!=0)
        ans=(ans*a)%mod;

        b/=2;
        a=(a*a)%mod;
    }
    return ans;
}
ll fact(ll n){
    ll ans=1;
    for(int i=n; i>=1; i--){
        ans*=i;
    }
    return ans;
}
int solve(){
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    ll height[n];
    for(int i=0; i<n; i++){
        cin>>height[i];
    }
    ll dp[n];
    memset(dp,63,sizeof(dp));
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<=i+k; j++){
            if(j<n)
            dp[j]=min(dp[j],dp[i]+abs(height[i]-height[j]));
        }
    }
    return dp[n-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

   // ll tc;
   // cin >> tc;
    //for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        ll ans=solve();
        cout<<ans<<"\n";
    //}
}
