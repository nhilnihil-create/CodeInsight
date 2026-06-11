#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> pint;

constexpr int INF = 1 << 30;
constexpr ll LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;

int main() {
    int n; cin >> n;
    vector<ll> a(n); rep(i, n) cin >> a[i];
    vector<ll> cum(n+1, 0);
    rep(i, n) {
        cum[i+1] = cum[i] + a[i];
    }

    int l = 1;
    int r = 3;
    ll ans = LINF;
    for (int m = 2; m <= n-2; m++) {
        if (r <= m) r = m+1;
        while (l+1 < m && abs(cum[l+1] - (cum[m] - cum[l+1])) <= abs(cum[l] - (cum[m] - cum[l]))) ++l;
        while (r+1 < n && abs(cum[r+1] - cum[m] - (cum[n] - cum[r+1])) <= abs(cum[r] - cum[m] - (cum[n] - cum[r]))) ++r;
        ll mn = min({cum[l], cum[m]-cum[l], cum[r]-cum[m], cum[n]-cum[r]});
        ll mx = max({cum[l], cum[m]-cum[l], cum[r]-cum[m], cum[n]-cum[r]});
        ans = min(ans, mx - mn);
    }

    cout << ans << endl;




    return 0;
}