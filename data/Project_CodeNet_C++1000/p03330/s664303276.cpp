// https://atcoder.jp/contests/abc099/tasks/abc099_d
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, C;
    cin >> N >> C;
    vector<vector<int>> D(C, vector<int>(C));
    REP(i, C) REP(j, C) { cin >> D[i][j]; }
    vector<vector<int>> E(N, vector<int>(N));
    REP(i, N) REP(j, N) {
        cin >> E[i][j];
        E[i][j]--;
    }
    // 予め色を変更した違和感を計算
    vector<vector<int>> cost(C, vector<int>(3));
    REP(c, C) REP(i, N) REP(j, N) { cost[c][(i + j) % 3] += D[E[i][j]][c]; }

    // 異なる色を３種類決める
    int minv = 1e9;
    REP(c1, C) {
        REP(c2, C) {
            if (c1 == c2)
                continue;
            REP(c3, C) {
                if (c1 == c3 || c2 == c3)
                    continue;
                minv = min(minv, cost[c1][0] + cost[c2][1] + cost[c3][2]);
            }
        }
    }
    cout << minv << endl;

    return 0;
}
