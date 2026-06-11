#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int n;
    ll z, w;
    cin >> n >> z >> w;
    ll a[n];
    rep(i, n) {
        cin >> a[i];
    }
    ll ans = abs(a[n - 1] - w);
    if (n > 1) ans = max(ans, abs(a[n - 1] - a[n - 2]));
    cout << ans << endl;
    return 0;
}