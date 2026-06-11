#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;

template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

int main() {
    ll n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    ll l = lcm(n, m);
    ll a = l / n;
    ll b = l / m;

    V<int> v(n), w(m);
    v[0] = 1, w[0] = 1;
    for(ll i = 1; i < n; i++) v[i] = v[i - 1] + a;
    for(ll i = 1; i < m; i++) w[i] = w[i - 1] + b;

    for(ll i = 0; i < n; i++){
        auto ite = lower_bound(ALL(w), v[i]);
        if(v[i] == *ite){
            ll j = ite - w.begin();
            if(s[i] == t[j]) continue;
            else{
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << l << endl;

    return 0;
}
