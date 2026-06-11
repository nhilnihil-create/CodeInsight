#include <bits/stdc++.h>
using namespace std;
#ifdef ENABLE_DEBUG_OUTPUT
#define DEBUG_LOG(s) cout << s << endl;
#else
#define DEBUG_LOG(s) void();
#endif

int main(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
    for (auto i = 0; i < m; i++) {
        int l, r; cin >> l >> r; sum[l][r]++;
    }

    for (auto i = 1; i <= n; i++) {
        for (auto j = 1; j <= n; j++) {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    for (auto i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        cout << sum[r][r] - sum[l - 1][r] << endl;
    }

    return 0;
}