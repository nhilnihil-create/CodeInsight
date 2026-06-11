#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    long long ans = 0;
    sort (a.begin(), a.end());
    for (auto p : a) {
        ans += p.first * min (m, p.second);
        m = max (0ll, m - p.second);
        if (m == 0) break;
    }
    cout << ans;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
