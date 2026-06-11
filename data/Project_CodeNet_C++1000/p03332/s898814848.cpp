#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
#include<stack>
#include<cstdio>
#include<bitset>
#include<unordered_map>
#include<climits>
#include<fstream>
using namespace std;
///////////////////library zone!!!!!!!!!!!!!!!!!!!!!!!!!!!!
typedef long long ll;
typedef long double ld;
#define all(a) (a).begin(),(a).end()
const ll mod = 1000000007;
const ll Mod = 998244353;
struct P {
	ll pos, cost;
	bool operator<(const P &b) const { return cost < b.cost; }
	bool operator>(const P &b) const { return cost > b.cost; }
};
struct B {
	ll to, cost;
};
struct E {
	ll from, to, cost;
	bool operator<(const E &b) const { return cost < b.cost; }
	bool operator>(const E &b) const { return cost > b.cost; }
};
struct H {
	ll x, y;
	bool operator<(const H &b) const {
		if (x != b.x) return x < b.x;
		return y < b.y;
	}
	bool operator>(const H &b) const {
		if (x != b.x) return x > b.x;
		return y > b.y;
	}
	bool operator==(const H &b) const { return x == b.x&&y == b.y; }
	bool operator!=(const H &b) const { return (*this) != b; }
};
ll gcd(ll i, ll j) {
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcd(j%i, i);
}
ll mod_pow(ll x, ll n, ll p = mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % p;
		x = x * x % p;
		n >>= 1;
	}
	return res;
}//x^n%p
const ll Inf = 3023372036854775807;
const int inf = 1500000000;
#define int long long
//----------------------------------------------------
int n, a, b, k;
int f[500000];
signed main() {
	cin >> n >> a >> b >> k;
	f[0] = 1;
	for (int i = 1; i < 400000; i++) {
		f[i] = f[i - 1] * i%Mod;
	}
	int ans = 0;
	for (int i = 0; i <= k; i += a) {
		int t = i / a;
		if (t > n) break;
		int r = (k - i) / b;
		if ((k - i) % b != 0) continue;
		if (r > n) continue;
		int res = f[n] * mod_pow(f[n - t], Mod - 2, Mod) % Mod*mod_pow(f[t], Mod - 2, Mod) % Mod;
		res = res * f[n] % Mod * mod_pow(f[n - r], Mod - 2, Mod) % Mod*mod_pow(f[r], Mod - 2, Mod) % Mod;
		ans += res;
		ans %= Mod;
	}
	cout << ans << endl;
}