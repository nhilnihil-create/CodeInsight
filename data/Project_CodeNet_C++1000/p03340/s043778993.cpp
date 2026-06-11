#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i,n) for (int i = 0; i < (n); ++i)
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    int rp = 0;
    ll ans = 0;
    ll sum = 0;
    ll xsum = 0;
    for ( int lp = 0; lp < n; ++lp ) {
        while(1) {
            if ( rp >= n || (sum + a[rp]) != (xsum ^ a[rp]) ) break;
            sum += a[rp];
            xsum ^= a[rp];
            ++rp;
        }
        ans += rp - lp;
        if ( rp == lp ) ++rp;
        else {
            sum -= a[lp];
            xsum ^= a[lp];
        }
    }
    cout << ans << endl;
    return 0;
}