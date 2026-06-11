#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N + 1, 0);
    rep(i, N) cin >> a[i + 1];

    rep(i, N) a[i + 1] += a[i];

    vector<vector<ll>> v(41);
    int cnt = 0;
    for (int l = 0; l < N; ++l) {
        for (int r = l + 1; r < N + 1; ++r) {
            v[40].push_back(a[r] - a[l]);
            ++cnt;
        }
    }

    ll ans = 0;

    int min_bit = 40;
    for (int i = 39; i >= 0; --i) {
        rep(j, v[min_bit].size()) {
            if (v[min_bit][j] & (1LL << i)) {
                v[i].push_back(v[min_bit][j]);
            }
        }

        if (v[i].size() >= K) {
            ans |= (1LL << i);
            min_bit = i;
        }
    }

    cout << ans << endl;
}