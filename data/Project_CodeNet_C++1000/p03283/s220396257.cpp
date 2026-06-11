#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n, m, q; cin >> n >> m >> q;

    vector<vector<int>> c(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int l, r; cin >> l >> r;
        --l; --r;

        c[l][r]++;
    }

    // 2次元累積和
    vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + c[i][j];
        }
    }

    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        --l; --r;

        cout << sum[r + 1][r + 1] - sum[r + 1][l] - sum[l][r + 1] + sum[l][l] << endl;
    }
}