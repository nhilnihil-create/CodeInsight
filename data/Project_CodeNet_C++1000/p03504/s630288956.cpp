#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    vector<vector<int>> R0(C, vector<int>(100000, 0));
    rep(i, N) {
        int s, t, c;
        cin >> s >> t >> c;
        ++R0[c - 1][s - 1];
        --R0[c - 1][t];
    }
    vector<vector<int>> R1(C, vector<int>(100000, 0));
    rep(i, C) R1[i][0] = R0[i][0];
    rep(i, C) REP(j, 100000) R1[i][j] = R1[i][j - 1] + R0[i][j];
    int ans = 0;
    rep(i, 100000) {
        int cnt = 0;
        rep(j, C) {
            if (R1[j][i]) ++cnt;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
