#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
using ll = long long;
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
int main() {
    ll n;
    cin>>n;
    vector<ll> v(n), c(n);
    for (ll i = 0; i < n;i++)cin>>v[i];
    for (ll i = 0; i < n;i++)cin>>c[i];
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += max(v[i] - c[i], 0LL);
    }
    cout << ans << endl;
}
