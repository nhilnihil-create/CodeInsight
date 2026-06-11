#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    rep(i, n) cin >> a[i];
    ll ans = gcd(a[0], a[1]);
    rep(i, n) {
        ans = gcd(ans, a[i]);
    }
    cout << ans << endl;
    return 0;
}

