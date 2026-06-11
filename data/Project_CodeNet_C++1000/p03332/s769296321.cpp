#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 998244353;

ll modpower(ll a, ll r){ //a^r
    ll x = 1;
    while (r > 0) {
        if (r & 1) x = x * a % mod;
        r >>= 1;
        a = a * a % mod;
    }
    return x;
}

ll modinv(ll a){
    return modpower(a, mod-2);
}

vector<ll> fact(300001, 1);
vector<ll> invfact(300001, 1);
ll modconv(ll n, ll k){
	if (k > n || k < 0) return 0;
	return fact[n] * invfact[k]%mod * invfact[n-k] % mod;
}

int main(){
    ll N, A, B, K;
    cin >> N >> A >> B >> K;
    
    for (int i = 2; i <= 300000; i++) fact[i] = (fact[i-1]*i)%mod;
    for (int i = 2; i <= 300000; i++) invfact[i] = modinv(fact[i]);
    ll ans = 0;
    for (ll i = 0; i <= N; i++) {
        if ((K-A*i)%B != 0) continue;
        ll j = (K-A*i)/B;
        if (j < 0 || j > N) continue;
        ans = (ans + modconv(N, i)*modconv(N, j))%mod;
    }
    cout << ans << endl;
    return 0;
}