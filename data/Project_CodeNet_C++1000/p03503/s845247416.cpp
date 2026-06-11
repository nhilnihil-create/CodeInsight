#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n; cin >> n;
    const int m = 10;

    vector<vector<int>> f(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> f[i][j];
        }
    }

    vector<vector<int>> p(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m + 1; j++) {
            cin >> p[i][j];
        }
    }

    int ans = -1000000000;
    for (int bit = 1; bit < (1 << m); ++bit) {
        int tmpProfit = 0;
        for (int i = 0; i < n; i++) { // shop
            int timeCnt = 0;
            for (int j = 0; j < m; ++j) { // time
                if (bit & (1 << j)) {
                    if (f[i][j] == 1) timeCnt++;
                }
            }
            tmpProfit += p[i][timeCnt];
        }
        ans = max(ans, tmpProfit);
    }

    cout << ans << endl;
    return 0;
}