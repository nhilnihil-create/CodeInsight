#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int mod = 998244353;
const int N = 3e5+5;
ll fac[N], ifac[N], inv[N];

int main(){
    //ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,a,b,k;
    cin >> n >> a >> b >> k;

    fac[0] = 1; ifac[0] = 1;
    fac[1] = 1; ifac[1] = 1;
    for(ll i = 2; i <= n; i++){
        fac[i] = fac[i-1]*i;
        fac[i] %= mod;
    }

    inv[1] = 1;
    for(ll i = 2; i <= n; i++){
        inv[i] = mod - (mod/i)*inv[mod%i]%mod;
        ifac[i] = ifac[i-1]*inv[i];
        ifac[i] %= mod;
        //cout << ifac[i] << endl;
    }

    ll answer = 0;
    for(ll x = 0; x <= n; x++){
        if(k-a*x < 0) break;
        if((k-a*x)%b) continue;
        ll y = (k-a*x)/b;
        if(y > n) continue;
        ll t = ((fac[n]*ifac[x])%mod*ifac[n-x])%mod;
        ll p = ((fac[n]*ifac[y])%mod*ifac[n-y])%mod;
        answer += t*p%mod;
        answer %= mod;
    }

    cout << answer << endl;
}
