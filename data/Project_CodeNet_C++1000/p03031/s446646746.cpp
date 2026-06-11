#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m, x, co1 = 0, co2 = 0, ans = 0;
    cin >> n >> m;
    vector<vector<int>> a(m);
    rep(i, m) {
        cin >> x;
        a[i].push_back(x);
        rep(j, a[i][0]) {
            cin >> x;
            a[i].push_back(x);
        }
    }
    vector<int> p(m);
    rep(i, m) cin >> p[i];
    for (int bit = 0; bit < (1 << n); ++bit) {
        vector<int> on;
        co2 = 0;
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i))
                on.push_back(i + 1);
        }
        for (int i = 0; i < m; ++i) {
            co1 = 0;
            for (int j = 1; j <= a[i][0]; ++j) {
                for (int k = 0; k < on.size(); ++k) {
                    if (on[k] == a[i][j])
                        co1++;
                }
            }
            if (co1 % 2 == p[i])
                co2++;
        }
        if (co2 == m)
            ans++;
    }
    cout << ans << endl;
}