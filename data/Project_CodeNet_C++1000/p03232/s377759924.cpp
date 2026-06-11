#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <iomanip>
#include <bitset>
using namespace std;

typedef long long ll;

constexpr int MAX_N = 100003;
constexpr ll mod = 1e9 + 7;

ll powm(ll x, ll p) {
	if (p == 0) return 1;
	ll res = powm(x, p / 2);
	res *= res;
	res %= mod;
	if (p % 2LL == 1) {
		res *= x;
		res %= mod;
	}
	return res;
}



int main() {
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<ll> ac(n + 2);
	for (int i = 1; i <= n; i++) {
		ac[i] = (ac[i - 1] + powm(i, mod - 2)) % mod;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll coef = ac[i + 1] + ac[n - i] - ac[1];
		ans += coef*a[i] % mod;
		ans %= mod;
	}
	ll fact = 1;
	for (ll i = 2; i <= n; i++) fact = (fact*i) % mod;
	cout << fact*ans % mod << endl;
	return 0;
}
