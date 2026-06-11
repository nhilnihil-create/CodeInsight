#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
typedef vector<vector<P>> vvP;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

// aのn乗を求める。計算量はO(logn)
ll modpow(ll a, ll n) {
    if(n == 0) {
        return 1;
    }
    if(n%2 == 1) {
        return (a * modpow(a, n-1))%mod;
    }
    return (modpow(a, n/2) * modpow(a, n/2))%mod;
}

ll inverse(ll a) {
    return modpow(a, mod-2);
}

ll inv[MAX_N];  // inv[i] : iの逆数のmod
ll fact[MAX_N];  // fact[i] : iの階乗のmod
ll invfact[MAX_N];

void init() {
    inv[0] = fact[0] = invfact[0] = 1;
    inv[1] = 1;
    for(ll i = 1; i < MAX_N; i++) {
        if(i >= 2) {
            inv[i] = mod - inv[mod%i]*(mod/i)%mod;
        }
        fact[i] = (i * fact[i-1])%mod;
        invfact[i] = inverse(fact[i]);
    }
}

//--- main関数でinit()を呼び出すのを忘れるな ---//
int main() {
    ll n;
    cin >> n;

    vl a(n);
    rep(i, n) {
        cin >> a[i];
    }

    init();

    vl rui(101010);  // rui[i] : inv[0]からinv[i]までの和
    rui[1] = 1;
    rep(i, n) {
        rui[i+2] = (rui[i+1] + inv[i+2])%mod;
    }

    ll ans = 0;
    rep(i, n) {
        ans += a[i]*(rui[i+1] + rui[n-i] - 1)%mod;
        ans %= mod;
    }
    ans *= fact[n];
    ans %= mod;

    out(ans);
    re0;
};