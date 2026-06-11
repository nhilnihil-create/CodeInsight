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
    cin >> n;
    ll a[n];
    ll gcdofl[n + 1];
    ll gcdofr[n + 1];
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
}
gcdofl[0] = 0;
gcdofr[n] = 0;
for (ll i = 0; i < n; i++) {
    gcdofl[i + 1] = __gcd(gcdofl[i], a[i]);
}
for (ll i = n-1; i >=0 ;i--){
    gcdofr[i] = __gcd(gcdofr[i+1], a[i]);
}
ll ans = 0;
for (ll i = 0; i < n; i++) {
    chmax(ans, __gcd(gcdofl[i], gcdofr[i+1]));
}
cout << ans << endl;
}
