#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

void solve();

signed main() {
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif // ONPC
    //freopen("time.in", "r", stdin);
    //freopen("time.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

const int N = 2e5 + 5;
const int lg = 20;
ll n, a[N], lef[N][lg + 1];
ll ans;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < lg; ++j) {
            lef[i][j] = lef[i - 1][j];
            if (i != 1 && ((1 << j) & a[i - 1])) lef[i][j] = i - 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        ll l = 0;
        for (int j = 0; j < lg; ++j) {
            if ((1 << j) & a[i]) {
                l = max(l, lef[i][j] + 1);
            } else {
                l = max(l, lef[lef[i][j]][j] + 1);
            }
        }
        ans += i - l + 1;
    }
    cout << ans;
}
