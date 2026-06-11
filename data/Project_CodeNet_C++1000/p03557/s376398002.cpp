#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];

    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    ll ans = 0;

    for (auto x : b) {
        ll cnta = lower_bound(a.begin(), a.end(), x) - a.begin();
        ll cntc = c.end() - upper_bound(c.begin(), c. end(), x);
        ans += cnta*cntc;
    }
    cout << ans << endl;
    return 0;
}