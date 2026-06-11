#include <bits/stdc++.h>
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, q;
    cin >> n >> m >> q;
    vector < vector < int > > trains(n + 1, vector < int >(n + 1, 0));
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        ++trains[l][r];
    }
    vector < vector < int > > pref(n + 1, vector < int >(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + trains[i][j];
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << pref[n][r] - pref[l - 1][r] - pref[n][0] + pref[l - 1][0] << '\n';
    }
}
