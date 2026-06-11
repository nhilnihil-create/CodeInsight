#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    int n, c;
    cin >> n >> c;
    vector<vector<int>> d(c, vector<int>(c));
    rep(i, c) rep(j, c) cin >> d[i][j];
    vector<vector<int>> counts(3, vector<int>(c));
    rep(i, n) rep(j, n) {
        int d;
        cin >> d;
        counts[(i+j) % 3][d - 1]++;
    }
    int ans = 1e9;
    for (int c1 = 0; c1 < c; c1++) {
        for (int c2 = 0; c2 < c; c2++) {
            for (int c3 = 0; c3 < c; c3++) {
                if (c1 == c2 || c2 == c3 || c1 == c3) continue;
                int iwa = 0;
                rep(i, c) {
                    iwa += d[i][c1] * counts[0][i];
                    iwa += d[i][c2] * counts[1][i];
                    iwa += d[i][c3] * counts[2][i];
                }
                ans = min(ans, iwa);
            }
        }
    }
    cout << ans << endl;
    return 0;
}