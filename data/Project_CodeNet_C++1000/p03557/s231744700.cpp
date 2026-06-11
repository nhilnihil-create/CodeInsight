#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    ll n; cin >> n;
    V<ll> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));

    ll sum = 0;
    for(int i = 0; i < n; i++){
        auto itea = lower_bound(all(a), b[i]);
        auto itec = upper_bound(all(c), b[i]);
        sum += (itea - a.begin()) * (c.end() - itec);
    }
    cout << sum << endl;

}
