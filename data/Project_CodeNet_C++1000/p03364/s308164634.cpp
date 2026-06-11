#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    rep(i, n) cin >> grid[i];

    int ans = 0;
    for (int a = 0; a < n; a++) {
        bool can = true;
        rep(i, n) {
            rep(j, n) {
                if (grid[(i + a) % n][j] != grid[(j + a) % n][i]) {
                    can = false;
                    break;
                }
            }
            if (!can) break;
        }
        if (can) ans += n;
    }
    cout << ans << endl;
}