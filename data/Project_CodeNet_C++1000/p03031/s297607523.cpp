#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
    int n, m;
    cin >> n >> m;
    int k[m], s[m][10];
    rep(i, 0, m) {
        cin >> k[i];
        rep(j, 0, k[i]) {
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    int p[m];
    rep(i, 0, m) cin >> p[i];
    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        int sum = 0;
        rep(i, 0, m) {
            int cnt = 0;
            rep(j, 0, k[i]) {
                if (bit & (1 << s[i][j])) cnt++;
            }
            if (cnt % 2 == p[i]) sum++;
        }
        if (sum == m) ans++;
    }
    cout << ans << "\n";
}