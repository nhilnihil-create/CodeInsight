#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n; cin >> n;
    V<ll> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    sort(ALL(a));
    sort(ALL(c));
    ll ans = 0;
    for(int i = 0; i < n; i++){
        auto itea = lower_bound(ALL(a), b[i]);
        auto itec = upper_bound(ALL(c), b[i]);
        ll aa = itea - a.begin();
        ll cc = c.end() - itec;
        ans += aa * cc;
    }
    cout << ans << endl;

    return 0;
}
