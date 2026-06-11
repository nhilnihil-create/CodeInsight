#include <iostream>
#include <vector>
#include <utility>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
ll inv[123456];
ll sum[123456];
ll mod_pow(ll a,ll b = mod-2){
    if(b==0)return 1;
    if(b==1)return a;
    if(b%2==0){
        ll res = mod_pow(a,b/2);
        return res*res%mod;
    }else{
        ll res = mod_pow(a,b/2);
        return res*res%mod*a%mod;
    }
}
int main(){
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
        inv[i] = mod_pow(i);
        sum[i] = (sum[i-1] + inv[i])%mod;
    }
    vector<ll>a(n);
    rep(i,n)cin >> a[i];
    ll ans = 0;
    rep(i,n){
        ans += a[i]*sum[n-i]+a[i]*sum[i+1]+mod-a[i];
        ans %= mod;
    }
    for(ll i = 1; i <= n; i++){
        ans *= i;
        ans %= mod;
    }
    cout << ans << endl;
}
