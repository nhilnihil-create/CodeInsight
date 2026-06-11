#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    pair<int, int> p[n];
    rep(i, n) cin >> p[i].first >> p[i].second;
    sort(p, p + n);

    ll ans = 0, cnt = 0;
    rep(i, n) {
        rep(j, p[i].second) {
            ans += p[i].first;
            cnt++;
            if (cnt >= m) break;
        }

        if (cnt >= m) break;
    }

    cout << ans << endl;
    return 0;
}
