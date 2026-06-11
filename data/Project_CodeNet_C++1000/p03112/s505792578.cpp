#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1001001001001;

int main() {
    int a, b, q;
    cin >> a >> b >> q;
    ll s[a], t[b];
    for (int i = 0; i < a; i++) cin >> s[i];
    for (int i = 0; i < b; i++) cin >> t[i];
    for (int i = 0; i < q; i++) {
        ll x;
        cin >> x;
        ll ans = INF;
        int idx1 = lower_bound(s, s + a, x) - s;
        int idx2 = lower_bound(t, t + b, x) - t;
        if (idx1 < a && idx2 < b) ans = min(ans, abs(x - max(s[idx1], t[idx2])));
        if (idx1 > 0 && idx2 < b) ans = min(ans, abs(x - s[idx1 - 1]) + abs(s[idx1 - 1] - t[idx2]));
        if (idx1 > 0 && idx2 < b) ans = min(ans, abs(x - t[idx2]) + abs(t[idx2] - s[idx1 - 1]));
        if (idx1 < a && idx2 > 0) ans = min(ans, abs(x - t[idx2 - 1]) + abs(t[idx2 - 1] - s[idx1]));
        if (idx1 < a && idx2 > 0) ans = min(ans, abs(x - s[idx1]) + abs(s[idx1] - t[idx2 - 1]));
        if (idx1 > 0 && idx2 > 0) ans = min(ans, abs(x - min(s[idx1 - 1], t[idx2 - 1])));
        cout << ans << endl;
    }
}