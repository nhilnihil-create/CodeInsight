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
   ll a[n],b[n],c[n];
   for(int i=0; i<n; i++){
       cin>>a[i]>>b[i]>>c[i];
   }
   ll dp[n][3];
   dp[0][0]=a[0];
   dp[0][1]=b[0];
   dp[0][2]=c[0];
   for(int i=1; i<n; i++){
       dp[i][0]=a[i]+max(dp[i-1][1],dp[i-1][2]);
       dp[i][1]=b[i]+max(dp[i-1][0],dp[i-1][2]);
       dp[i][2]=c[i]+max(dp[i-1][0],dp[i-1][1]);
   }
   return *max_element(dp[n-1],dp[n-1]+3);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    //ll tc;
    //cin >> tc;
    //for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        ll ans=solve();
        cout<<ans<<"\n";
    //}
}
