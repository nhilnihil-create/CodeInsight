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
int n, x;
int a[1000000];
int b[1000000];
signed main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i] + (i > 0 ? b[i - 1] : 0);
	}
	unsigned int ans = 18446744073709551615;
	for (int i = 1; i <= n; i++) {
		unsigned int sum = x * i;
		int res = 3;
		sum += 5 * (b[n - 1] - (n - i - 1 < 0 ? 0 : b[n - i - 1]));
		for (int j = n - i - 1; j >= 0; j -= i) {
			sum += (res*res - (res - 1)*(res - 1))*(b[j] - (j - i < 0 ? 0 : b[j - i]));
			res++;
		}
		ans = min(ans, sum + n * x);
	}
	cout << ans << endl;
}