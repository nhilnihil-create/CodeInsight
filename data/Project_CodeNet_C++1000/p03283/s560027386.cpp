#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n, m, Q; cin >> n >> m >> Q;

    vector<vector<int>> c(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int l, r; cin >> l >> r;
        --l; --r;

        c[l][r]++;
    }

    vector<vector<int>> sum(n, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum[i][j + 1] = sum[i][j] + c[i][j];
        }
    }

    for (int i = 0; i < Q; ++i) {
        int p, q; cin >> p >> q;
        --p; --q;

        int ans = 0;
        for (int j = p; j <= q; ++j) {
            ans += sum[j][q + 1] - sum[j][p];
        }

        cout << ans << endl;
    }
}