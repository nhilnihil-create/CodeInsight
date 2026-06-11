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

ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extgcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

int main(){
    ll N, A, B, K;
    cin >> N >> A >> B >> K;
    ll X, Y;
    ll G = extgcd(A, B, X, Y);
    if (K % G != 0) {
        cout << 0 << endl;
        return 0;
    }
    X *= (K/G);
    Y *= (K/G);
    
    //cout << X << " " << Y << endl;
    
    for (int i = 2; i <= 300000; i++) fact[i] = (fact[i-1]*i)%mod;
    for (int i = 2; i <= 300000; i++) invfact[i] = modinv(fact[i]);
    ll s = X, t = Y;
    if (t < 0) {
        ll p = (-t)/(A/G);
        t += p*(A/G);
        s -= p*(B/G);
    }
    ll ans = 0;
    while (s >= 0) {
        if (t >= 0) {
            ans = (ans+(modconv(N, s) * modconv(N, t))) % mod;
        }
        s -= B/G;
        t += A/G;
    }
    s = X+B/G;
    t = Y-A/G;
    if (s < 0) {
        ll p = (-s)/(B/G);
        t -= p*(A/G);
        s += p*(B/G);
    }
    while (t >= 0) {
        if (s >= 0) {
            ans = (ans+(modconv(N, s) * modconv(N, t)))%mod;
        }
        s += B/G;
        t -= A/G;
    }
    cout << ans << endl;
    return 0;
}