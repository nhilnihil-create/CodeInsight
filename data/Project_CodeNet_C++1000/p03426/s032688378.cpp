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

    int H, W, D;
    cin >> H >> W >> D;
    vector<vector<int>> A(H, vector<int>(W));
    vector<P> invA(H * W);
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
            A[i][j]--;
            invA[A[i][j]] = P(i, j);
        }
    }
    vector<int> dp(H * W);
    REP(d, D) {
        for (int x = d; x + D < H * W; x += D) {
            int i, j, k, l;
            tie(i, j) = invA[x];
            tie(k, l) = invA[x + D];
            dp[x + D] = dp[x] + abs(i - k) + abs(j - l);
        }
    }
    int Q;
    cin >> Q;
    REP(q, Q) {
        int L, R;
        cin >> L >> R;
        --L;
        --R;
        cout << dp[R] - dp[L] << endl;
    }

    return 0;
}
