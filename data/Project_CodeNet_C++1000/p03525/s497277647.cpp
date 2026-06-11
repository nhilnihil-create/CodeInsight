#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

class Main {
    int N;
    vector<int> D;
    void input() {
        cin >> N;
        D.resize(N);
        REP(i, N) { cin >> D[i]; }
    }
    void output() {
        vector<int> cnt(13);
        cnt[0] = 2;
        cnt[12] = 1;
        REP(i, N) { cnt[D[i]]++; }
        if (*max_element(cnt.begin(), cnt.end()) >= 3) {
            cout << 0 << endl;
            return;
        }
        vector<int> two = {0}, one;
        FOR(i, 1, 12) {
            if (cnt[i] == 2) {
                two.emplace_back(i);
                two.emplace_back(24 - i);
            } else if (cnt[i] == 1) {
                one.emplace_back(i);
            }
        }
        if (cnt[12] == 2) two.emplace_back(12);
        int n = one.size();
        int res = 0;
        REP(bit, 1 << n) {
            vector<int> v = two;
            REP(j, n) {
                if (bit >> j & 1) {
                    v.emplace_back(one[j]);
                } else {
                    v.emplace_back(24 - one[j]);
                }
            }
            int mn = 12;
            REP(i, N) {
                FOR(j, i + 1, N + 1) {
                    int d = abs(v[i] - v[j]);
                    d = min(d, 24 - d);
                    mn = min(mn, d);
                }
            }
            res = max(mn, res);
        }
        cout << res << endl;
    }

public:
    Main() {
        input();
        output();
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Main();

    return 0;
}
