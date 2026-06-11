#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main() {
    int n; cin >> n;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    sort(l.begin(), l.end(), greater<>{});
    sort(r.begin(), r.end());

    ll ans = 0, sum_l = 0, sum_r = 0;
    for(int i = 0; i < n; ++i) {
        sum_l += 2 * l[i];
        sum_r += -2 * r[i];
        ans = max(ans, sum_l + sum_r);
        ans = max(ans, sum_l - 2 * l[i] + sum_r);
        ans = max(ans, sum_l + sum_r + 2 * r[i]);
    }

    cout << ans << endl;
}
