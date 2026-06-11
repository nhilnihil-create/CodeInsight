#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N, C; cin >> N >> C;
    vector<vector<int>> D(C, vector<int>(C));
    vector<vector<int>> c(N, vector<int>(N));
    REP(i, 0, C) REP(j, 0, C) cin >> D[i][j];
    REP(i, 0, N) REP(j, 0, N) cin >> c[i][j];

    vector<vector<int>> cnt(3, vector<int>(C, 0));
    REP(i, 0, N) REP(j, 0, N) cnt[(i + j) % 3][c[i][j] - 1]++;

    int ans = 1 << 30;
    REP(i, 0, C) {
        REP(j, 0, C) {
            REP(k, 0, C) {
                if (i == j || j == k || i == k) continue;
                int sum = 0, colors[3];
                colors[0] = i; colors[1] = j; colors[2] = k;
                REP(l, 0, 3) {
                    REP(m, 0, C) {
                        sum += cnt[l][m] * D[m][colors[l]];
                    }
                }
                ans = min(ans, sum);
            }
        }
    }
    cout << ans << endl;
    return 0;
}