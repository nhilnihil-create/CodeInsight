#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    ll p = lcm(n, m);
    vector<ll> s_index;
    vector<ll> t_index;
    for (ll i = 0; i < n; i+=p/m) {
        s_index.push_back(i);
    }
    for (int i = 0; i < m; i+=p/n) {
        t_index.push_back(i);
    }
    bool ok = true;
    rep(i,s_index.size()) {
        if (s[s_index[i]] != t[t_index[i]]) {
            ok = false;
        }
    }
    ll ans;
    if (ok) ans = p;
    else ans = -1;
    cout << ans << endl;
}