#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    ll n, m;
    ll ans = 0;
    cin >> n >> m;
    ll minR, maxL;
    minR = 1e7;
    maxL = -1;
    ll r, l;
    rep(i, m){
        cin >> l >> r;
        minR = min(minR, r);
        maxL = max(maxL, l);
    }
    ans = minR - maxL + 1;
    if (ans < 0) {
        ans = 0;
    }
    cout << ans << endl;
    return 0;
}

