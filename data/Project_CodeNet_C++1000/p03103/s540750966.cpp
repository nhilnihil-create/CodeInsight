#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    pair<ll, int> p[n];
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        p[i] = {a, b};
    }
    sort(p, p + n);

    ll ans = 0;
    rep(i, n) {
        if (m <= p[i].second)
            ans += m * p[i].first, m = 0;
        else
            ans += p[i].first * p[i].second, m -= p[i].second;

        if (m == 0) break;
    }

    cout << ans << endl;
    return 0;
}
