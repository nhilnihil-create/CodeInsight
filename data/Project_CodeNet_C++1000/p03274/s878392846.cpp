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
    ll n, k;
    cin >> n >> k;
    ll x[n];
    ll ans = INF;
    for (ll i = 0; i < n; i++) cin >> x[i];
    for (ll i = 0; i < n - k+1; i++){
        ans = min(ans, min(abs(x[i]) + x[i + k - 1] - x[i], abs(x[i + k - 1]) + x[i + k - 1] - x[i]));
    }
    cout << ans << endl;
}