#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;

signed main() {
    int n;
    cin >> n;
    int f[n][10];
    int p[n][11];
    rep (i, 0, n) rep (j, 0, 10) cin >> f[i][j];
    rep (i, 0, n) rep (j, 0, 11) cin >> p[i][j];
    int ans = -inf;
    rep (bit, 1, 1 << 10) {
        int sum = 0;
        rep (i, 0, n) {
            int cnt = 0;
            rep (j, 0, 10) {
                if (f[i][j] && (bit & (1 << j))) cnt++;
            }
            sum += p[i][cnt];
        }
        // cout << sum << " ";
        ans = max (ans, sum);
    }
    cout << ans << "\n";
}
