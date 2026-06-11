#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(v) for (auto itr = v.begin(), itr != v.end(); ++itr)
#define LB(v, x) lower_bound(v.begin(), v.end(), x) - v.begin()
#define UB(v, x) upper_bound(v.begin(), v.end(), x) - v.begin()
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<vector<vector<int>>> F(N);
    REP(i, N) {
        F[i].resize(5, vector<int>(2));
        REP(j, 5) REP(k, 2) cin >> F[i][j][k];
    }
    vector<vector<int>> P(N);
    REP(i, N) {
        P[i].resize(11);
        REP(j, 11) cin >> P[i][j];
    }
    int res = INT_MIN;
    for (int bit = 1; bit < (1 << 10); ++bit) {
        vector<int> c(N);
        REP(i, 5) {
            REP(j, 2) {
                if (bit >> (2 * i + j) & 1) { REP(k, N) c[k] += F[k][i][j]; }
            }
        }

        int sum = 0;
        REP(i, N) sum += P[i][c[i]];
        res = max(res, sum);
    }
    cout << res << endl;

    return 0;
}
