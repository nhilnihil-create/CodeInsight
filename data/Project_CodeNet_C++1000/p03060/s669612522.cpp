#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n), c(n);
    rep(i, 0, n) cin >> v[i];
    rep(i, 0, n) cin >> c[i];
    ll ans = 0;
    rep(i, 0, n) ans += max(0LL, v[i]-c[i]);
    cout << ans << endl;
    return 0;
}