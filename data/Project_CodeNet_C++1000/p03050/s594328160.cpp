#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

vector<ll> calc_divisor(ll n) {
    vector<ll> res;
    for (ll i = 1LL; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            ll j = n / i;
            if (j != i) res.push_back(j);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    vector<ll> divs = calc_divisor(N);
    for (auto d : divs) {
        ll m = d - 1;
        if (m == 0) continue;
        if (N / m == N % m) ans += m;
    }

    cout << ans << endl;
}