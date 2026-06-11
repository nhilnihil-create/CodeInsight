#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    vector<vector<int>> D(C, vector<int>(C));
    rep(i, C) rep(j, C) cin >> D[i][j];
    vector<vector<int>> c(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> c[i][j];
    
    vector<vector<int>> d(C, vector<int>(3, 0));
    rep(i, N) rep(j, N) rep(k, C) d[k][(i + j) % 3] += D[c[i][j] - 1][k];
    int ans = 1001001001;
    rep(i, C) rep(j, C) rep(k, C) {
        if (i == j || j == k || k == i) continue;
        ans = min(ans, d[i][0] + d[j][1] + d[k][2]);
    }
    cout << ans << endl;
    return 0;
}
