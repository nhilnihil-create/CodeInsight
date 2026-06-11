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
ll n,X;
cin >> n >> X;
ll x[n];
for (ll i = 0; i < n; i++) cin >> x[i];
ll y[n+1];
y[0] = 0;
for (ll i = 0; i < n; i++) y[i + 1] = x[i] % X;
ll ans = 0;
for (ll i = 1; i < n + 1; i++) ans = __gcd(ans, abs(X-x[i-1]));
cout << ans << endl;
}