#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int INF = (int)1e9 + 7;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> cost(m, vector<int>(m));
    for (auto &vi: cost) for (auto &vij: vi) cin >> vij;
    vector<vector<int>> cnt(3, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        int c; cin >> c, c--;
        cnt[(i + j) % 3][c]++;
    }
    int mi = INF;
    #define rep(i, n) for (int i = 0; i < n; i++)
    rep(i, m) rep(j, m) if (i != j) rep(k, m) if (i != k && j != k) {
        int tmp = 0;
        rep(c, m) tmp += cnt[0][c] * cost[c][i];
        rep(c, m) tmp += cnt[1][c] * cost[c][j];
        rep(c, m) tmp += cnt[2][c] * cost[c][k];
        mi = min(mi, tmp);
    }
    cout << mi << endl;
    return 0;
}
