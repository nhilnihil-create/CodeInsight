#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n; cin >> n;
    V<ll> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    sort(ALL(a));
    sort(ALL(b));
    sort(ALL(c));

    ll ans = 0;
    for(int i = 0; i < n; i++){
        auto ite1 = lower_bound(ALL(a), b[i]);
        auto ite2 = upper_bound(ALL(c), b[i]);
        ans += (ite1 - a.begin()) * (c.end() - ite2);
    }
    cout << ans << endl;

    return 0;
}
