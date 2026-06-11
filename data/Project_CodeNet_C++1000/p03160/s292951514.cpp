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
    ll height[n];
    for(int i=0; i<n; i++){
        cin>>height[i];
    }
    ll dp[n];
    dp[0]=0;
    dp[1]=abs(height[0]-height[1]);
    for(int i=2; i<n; i++){
        dp[i]=min(dp[i-1]+abs(height[i]-height[i-1]),dp[i-2]+abs(height[i]-height[i-2]));
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
