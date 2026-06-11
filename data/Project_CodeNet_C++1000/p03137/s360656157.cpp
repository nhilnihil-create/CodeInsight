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
    ll n, m;
    cin >> n >> m;
    ll a[m];
    for (ll i = 0; i < m; i++) cin >> a[i];
    sort(a, a + m);
    ll dist[m];
    dist[0] = 0;
    for (ll i = 0; i < m - 1; i++) {
        dist[i + 1] = a[i + 1] - a[i];
    }
    sort(dist, dist + m);
    ll ans = 0;
    if (n >= m) ans = 0;
    else{
        for (ll i = 0; i < m - n+1; i++) ans += dist[i];
    }
    cout << ans << endl;
}