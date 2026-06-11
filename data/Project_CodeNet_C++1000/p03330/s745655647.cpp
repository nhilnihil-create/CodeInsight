#include <iostream>
#include <vector>
#define rep(i, n) for(int (i)=0;(i)<(n);++(i))
using namespace std;

const int INF = 1001001001;

int main() {
    int n, c; cin >> n >> c;
    vector<vector<int>> d(c, vector<int>(c, 0));
    vector<vector<int>> grid(n, vector<int>(n, 0));
    rep(i, c)rep(j, c) cin >> d[i][j];
    rep(i, n)rep(j, n) {
        cin >> grid[i][j];
        --grid[i][j];
    }

    // cost[i][j] あまりがiのマスをj色に塗るのにかかるコスト
    vector<vector<int>> cost(3, vector<int>(c, 0));
    rep(i, n)rep(j,n)rep(color, c) cost[(i + j) % 3][color] += d[grid[i][j]][color];

    int ans = INF;
    rep(c0, c)rep(c1, c)rep(c2,c) {
        if (c0 == c1 || c1 == c2 || c2 == c0) continue;
        ans = min(ans, cost[0][c0] + cost[1][c1] + cost[2][c2]);
    }

    cout << ans << endl;
}