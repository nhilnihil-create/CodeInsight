#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n; cin >> n;
    V<ll> a(n);
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        x -= (i + 1);
        a[i] = x;
    }

    sort(ALL(a));
    ll m = a[n / 2];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(a[i] - m);
    }
    cout << ans << endl;


    return 0;
}
