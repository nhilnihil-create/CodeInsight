#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
    int n; cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());      
    ll ans = 0;
    for (int j = 0; j < n; j++) {
        ll na = lower_bound(a.begin(), a.end(), b[j]) - a.begin();
        ll nc = c.end() - upper_bound(c.begin(), c.end(), b[j]);
        ans += na * nc;
    }
    cout << ans << endl;
    return 0;
}