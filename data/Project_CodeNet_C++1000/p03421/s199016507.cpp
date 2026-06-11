#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b > n + 1 || (ll)a * b < n) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    vector<int> now;
    int cnt = 0;
    rep(i, n) {
        if (n + 1 - i == a) {
            reverse(ALL(now));
            for (auto t : now) {
                ans.emplace_back(t);
            }
            now.resize(0);
            a--;
        } else if (cnt == b) {
            reverse(ALL(now));
            for (auto t : now) {
                ans.emplace_back(t);
            }
            now.resize(0);
            a--;
            cnt = 0;
        }
        now.emplace_back(i + 1);
        cnt++;
    }
    reverse(ALL(now));
    for (auto t : now) {
        ans.emplace_back(t);
    }
    rep(i, n) {
        cout << ans[i] << endl;
    }
    return 0;
}