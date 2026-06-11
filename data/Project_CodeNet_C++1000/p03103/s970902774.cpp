#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    pair<ll, int> d[n];
    rep(i, n) cin >> d[i].first >> d[i].second;
    sort(d, d + n);

    ll ans = 0, cnt = 0;
    rep(i, n) {
        if (cnt + d[i].second <= m) {
            ans += d[i].first * d[i].second;
            cnt += d[i].second;
        } else {
            ans += (m - cnt) * d[i].first;
            cnt = m;
        }
        if (cnt == m) break;
    }

    cout << ans << endl;
    return 0;
}
