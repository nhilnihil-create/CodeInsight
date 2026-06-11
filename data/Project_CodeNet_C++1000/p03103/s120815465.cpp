#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> p(n);
    rep(i, n) cin >> p[i].first >> p[i].second;

    sort(p.begin(), p.end());

    ll ans = 0;
    rep(i, n) {
        if (p[i].second < m) {
            ans += p[i].first * p[i].second;
            m -= p[i].second;
        } else {
            ans += p[i].first * m;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}