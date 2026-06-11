#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    int max_cnt = 0, D[13] = {}; D[0] = 1;
    REP(i, 0, N) {
        int d; cin >> d;
        D[d]++;
        max_cnt = max(max_cnt, D[d]);
    }

    if (D[0] > 1 || D[12] > 1 || max_cnt > 2) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> fixed, unfixed;
    REP(i, 1, 12) {
        if (D[i] == 2) {
            fixed.push_back(i);
            fixed.push_back(24 - i);
        } else if (D[i] == 1) {
            unfixed.push_back(i);
        }
    }
    if (D[0] > 0) fixed.push_back(0);
    if (D[12] > 0) fixed.push_back(12);

    auto fn = [](auto l, auto r) {
        return min({
            abs(l - r),
            min(l, r) + 24 - max(l, r),
        });
    };

    int base = 1 << 30;
    REP(i, 0, fixed.size()) {
        REP(j, i + 1, fixed.size()) {
            base = min(base, fn(fixed[i], fixed[j]));
        }
    }
    // cout << "base : " << base << endl;

    int ans = 0;
    for (int bit = 0; bit < (1 << unfixed.size()); bit++) {
        vector<int> times;
        REP(i, 0, unfixed.size()) {
            if (bit & (1 << i)) {
                times.push_back(unfixed[i]);
            } else {
                times.push_back((24 - unfixed[i]) % 24);
            }
        }

        // cout << "# ";
        // for (auto t : times) cout << t << " ";
        // cout << endl;

        int cur = base;
        REP(i, 0, fixed.size()) {
            REP(j, 0, times.size()) {
                cur = min(cur, fn(fixed[i], times[j]));
            }
        }
        // cout << "--> cur : " << cur << endl;
        REP(i, 0, times.size()) {
            REP(j, i + 1, times.size()) {
                cur = min(cur, fn(times[i], times[j]));
            }
        }
        // cout << "--> cur : " << cur << endl;
        ans = max(ans, cur);
    }

    cout << ans << endl;

    return 0;
}