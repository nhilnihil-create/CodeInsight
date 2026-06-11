#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;

template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

vector<pair<ll, ll> > prime_factorize(ll n){
    vector<pair<ll, ll> > res;
    for(ll i = 2; i * i <= n; i++){
        if(n % i != 0) continue;
        ll ex = 0;
        while(n % i == 0){
            ex++;
            n /= i;
        }
        res.push_back({i, ex});
    }
    if(n != 1) res.push_back({n, 1});
    return res;
}

int main() {
    ll n, p; cin >> n >> p;

    V<P<ll, ll> > pf = prime_factorize(p);
    ll ans = 1;
    for(auto p : pf){
        for(int i = 0; i < p.second / n; i++){
            ans *= p.first;
        }
    }
    cout << ans << endl;

    return 0;
}
