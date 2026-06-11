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
const ll Mod = 1000000007;
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
ll mod_pow(ll x, ll n, ll p = Mod) {
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
int n;
int a[200000];
signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += mod_pow(i, Mod - 2, Mod);
		sum %= Mod;
	}
	int fac = 1;
	for (int i = 1; i <= n; i++) {
		fac *= i;
		fac %= Mod;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i] * fac%Mod*sum%Mod;
		ans %= Mod;
		sum -= mod_pow(n - i, Mod - 2);
		sum %= Mod;
		sum += Mod;
		sum %= Mod;
		sum += mod_pow(i + 2, Mod - 2);
		sum %= Mod;
	}
	cout << (ans + Mod) % Mod << endl;
}