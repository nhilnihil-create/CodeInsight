#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll fac[300001],ifac[300001];

ll mpow(ll x,ll n){
    ll res = 1;
    while(n != 0){
        if(n&1) res = res*x % mod;
        x = x*x % mod;
        n = n >> 1; 
    }
    return res;
}
ll comb(ll a,ll b){
    if(a==0 && b==0) return 1;
    if(a<b || a<0) return 0;
    ll tmp = ifac[a-b]*ifac[b] % mod;
    return tmp*fac[a] % mod;
}

int main(){
    ll n,a,b,k,ans=0;
    cin >> n >> a >> b >> k;

    fac[0] = 1;
    ifac[0] = 1;
    for(int i = 0;i < 300000;i ++){
        fac[i+1] = fac[i]*(i+1) % mod;
        ifac[i+1] = ifac[i]*mpow(i+1,mod-2) % mod;
    }

    for(int x = 0;x <= n;x ++){
        ll y;
        if((k-a*x)%b==0) y = (k-a*x)/b;
        else continue;
        if(x<0||y<0) continue;
        ans += comb(n,x)*comb(n,y);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}