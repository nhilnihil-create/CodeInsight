#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        c[i] = a[i] + b[i];
    }
    ll ans = 0;
    sort(c.begin(), c.end(), greater<ll>());
    for (ll i = 0; i < n; i++) {
        if (i % 2 == 0) ans += c[i];
        ans -= b[i];
    }
    cout << ans << endl;
}