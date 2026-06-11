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
    vector<ll> h(n+1,0);
    ll ans = 0;
    for (ll i = 1; i < n + 1; i++) cin >> h[i];
    for (ll i = 0; i < n;i++){
        ans += max(0LL, h[i + 1] - h[i]);
    }
    cout << ans << endl;
}