/**
*    author:  boutarou
*    created: 18.07.2020 19:37:14
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); i++)
using ll = long long;
using P = pair<int, int>;

const ll INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<ll>a(n);
    rep(i, n) cin >> a[i];
    ll ans = a[0];
    rep(i, n) {
        ans = gcd(ans, a[i]);
    }
    cout << ans << endl;

    return 0;
}