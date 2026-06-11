#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define inf 1e9
#define INF 1000000000000000000

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> grid(510, vector<int>(510, 0));
    rep(i, M) {
        int l, r;
        cin >> l >> r;
        grid[l][r]++;
    }

    rep(i, 501) {
        rep(j, 501) {
            grid[i + 1][j + 1] +=
                (grid[i][j + 1] + grid[i + 1][j] - grid[i][j]);
        }
    }

    rep(i, Q) {
        int p, q;
        cin >> p >> q;
        int x1 = p - 1, x2 = q, y1 = p - 1, y2 = q;
        cout << grid[x2][y2] - grid[x1][y2] - grid[x2][y1] + grid[x1][y1]
             << endl;
    }
}