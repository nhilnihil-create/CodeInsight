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
vector<ll> a(n), b(n);
for (ll i = 0; i < n; i++) cin >> a[i];
for (ll i = 0; i < n; i++) cin >> b[i];
ll sum = 0;
for (ll i = 0; i < n; i++) {
    sum += (b[i] - a[i]);
}
ll cost1 = 0;
ll cost2 = 0;
for (ll i = 0; i < n; i++) {
    if (a[i] > b[i]) cost1 += (a[i] - b[i]);
    if (a[i] < b[i]) cost2 += (b[i] - a[i] + 1) / 2;
}
ll ans = -INF;
chmax(ans, cost1);
chmax(ans, cost2);
cout << ((sum >= ans) ? "Yes" : "No") << endl;
}