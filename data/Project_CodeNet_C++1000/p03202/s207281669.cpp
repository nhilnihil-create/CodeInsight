#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> as(n);
    for (int i = 0; i < n; i++) cin >> as[i];

    auto trim = [&](const vector<pair<int, int>> &as, int k) {
        vector<pair<int, int>> ret;
        for (auto &p : as) {
            if (p.second <= k) {
                ret.emplace_back(p);
                k -= p.second;
                if (k == 0) break;
            } else {
                ret.emplace_back(p.first, k);
                break;
            }
        }
        return ret;
    };

    auto increment = [&](vector<pair<int, int>> as, int k) {
        if (as.size() == 1 && as[0].first == k - 1) return vector<pair<int, int>>();
        if (as.back().first != k - 1) {
            auto t = as.back();
            as.pop_back();
            if (t.second > 1) {
                as.emplace_back(t.first, t.second - 1);
                as.emplace_back(t.first + 1, 1);
            } else {
                as.emplace_back(t.first + 1, 1);
            }
        } else {
            auto t = as.back();
            as.pop_back();
            auto u = as.back();
            as.pop_back();
            if (u.second > 1) {
                as.emplace_back(u.first, u.second - 1);
                as.emplace_back(u.first + 1, 1);
            } else {
                as.emplace_back(u.first + 1, 1);
            }
            as.emplace_back(0, t.second);
        }
        vector<pair<int, int>> ret;
        for (auto &p : as) {
            if (ret.empty() || ret.back().first != p.first) {
                ret.emplace_back(p);
            } else {
                ret.back().second += p.second;
            }
        }
        return ret;
    };

    auto ok = [&](int k) -> bool {
        vector<pair<int, int>> cur = {{0, as[0]}};
        for (int i = 1; i < n; i++) {
            if (as[i - 1] < as[i]) {
                if (cur.back().first == 0) {
                    cur.back().second += as[i] - as[i - 1];
                } else {
                    cur.emplace_back(0, as[i] - as[i - 1]);
                }
            } else {
                cur = trim(cur, as[i]);
                cur = increment(cur, k);
                if (cur.empty()) return false;
            }
        }
        return true;
    };

    int l = 0, r = n;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (ok(m)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r << endl;
}
