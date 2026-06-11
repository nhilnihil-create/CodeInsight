#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define REP(i, n) for (long long i = 0; i < (n); i++)
const ll INF = 1LL << 60;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
};
ll modpow(ll m, ll n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        ll t = modpow(m, n / 2);
        return t * t;
    } else {
        return modpow(m, n - 1) * m;
    }
}
signed main() {
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    ll l = (n * m) / __gcd(n, m);
    if (s[0] != t[0]) {
        cout << -1 << endl;
        return 0;
    }
    map<ll, ll> cnt;
    map<ll, ll> cnt2;
    for (int i = 1; i < n; i++) {
        cnt[(l / n) * i + 1]++;
        cnt2[(l / n) * i + 1] = i;
    }
    for (int i = 1; i < m; i++) {
        if (cnt[(l / m) * i + 1] > 0) {
            if (s[cnt2[(l / m) * i + 1]] != t[i]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << l << endl;
}