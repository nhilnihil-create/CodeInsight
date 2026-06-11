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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> s(M);
    REP(i, M) {
        int k;
        cin >> k;
        s[i].resize(k);
        REP(j, k) {
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    vector<int> p(M);
    REP(i, M) {
        cin >> p[i];
    }
    int res = 0;
    REP(bit, 1 << N) {
        auto ok = [&]() {
            REP(i, M) {
                int sum = 0;
                for (auto &k : s[i]) {
                    sum += (bit >> k & 1);
                }
                if (sum % 2 != p[i]) {
                    return 0;
                }
            }
            return 1;
        };
        res += ok();
    }
    cout << res << endl;

    return 0;
}