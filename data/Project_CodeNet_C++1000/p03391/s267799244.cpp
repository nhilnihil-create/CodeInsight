#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    bool eq = true;
    ll ans = 0, mn = LINF;
    ll a[n], b[n];
    rep(i, n) {
        cin >> a[i] >> b[i];
        if (a[i] != b[i]) eq = false;
        if (a[i] > b[i]) mn = min(mn, b[i]);
        ans += b[i];
    }
    if (eq) cout << 0 << endl;
    else cout << ans - mn << endl;
    return 0;
}