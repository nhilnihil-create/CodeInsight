#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<cmath>
#include<numeric>
#include<iomanip>
#include<functional>
#include<cstdlib>
#include<queue>
#include<deque>
#include <iterator>     // std::back_inserter
const double PI = acos(-1);
using namespace std;
using ll =long long;
#define rep(i,n)for(ll i=0;i<(n);i++)
const int mod = 1000000007;
const ll inf = 1e18 + 1;
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

ll gcd(ll a, ll b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
};
//fixed << setprecision(2)
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
//ll f[101010], rf[101010];
//ll inv(ll x) {
//	ll res = 1;
//	ll k = mod - 2;
//	ll y = x;
//	while (k) {
//		if (k & 1) res = (res * y) % mod;
//		y = (y * y) % mod;
//		k /= 2;
//	}
//	return res;
//}
//void init() {
//	f[0] = 1;
//	for (ll i = 1; i < 101010;i++) f[i] = (f[i - 1] * i) % mod;
//	for(ll i = 0; i < 101010; i++) rf[i] = inv(f[i]);
//}
////---------------------------------------------------------------------------------------------------
//ll C(int n, int k) {
//	ll a = f[n]; // = n!
//	ll b = rf[n - k]; // = (n-k)!
//	ll c = rf[k]; // = k!
//
//	ll bc = (b * c) % mod;
//
//	return (a * bc) % mod;
//}

//小文字=大文字+32
int main() {
	int N; cin >> N;
	vector<ll>a(N); rep(i, N) { cin >> a[i];}
	vector<ll>c(N); rep(i, N) { cin >> c[i];}
	ll ans = 0;
	rep(i, N) {
		if (a[i] - c[i] > 0) {
			ans += a[i] - c[i];
		}
	}
	cout << ans;
	
}