#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
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
#define EPS (1e-5)
#define bit(n,k) ((n>>k)&1)
const ll Mod = 1000000007;
const ll mod = 998244353;
struct H {
	ll x, y;
	bool operator<(const H& b) const {
		if (x != b.x) return x < b.x;
		return y < b.y;
	}
	bool operator>(const H & b) const {
		if (x != b.x) return x > b.x;
		return y > b.y;
	}
	bool operator==(const H & b) const { return x == b.x && y == b.y; }
	bool operator!=(const H & b) const { return (*this) != b; }
};
struct P {
	ll pos, cost;
	bool operator<(const P& b) const { return cost < b.cost; }
	bool operator>(const P& b) const { return cost > b.cost; }
};
struct B {
	ll to, cost;
};
struct E {
	ll from, to, cost;
	bool operator<(const E& b) const { return cost < b.cost; }
	bool operator>(const E& b) const { return cost > b.cost; }
};
template<typename T, typename U>
void chmin(T & a, U b) {
	if (a > b) a = b;
}
template<typename T, typename U>
void chmax(T & a, U b) {
	if (a < b) a = b;
}
template<typename T>
T max_0(T a) {
	if (a < 0) return 0;
	return a;
}
template<typename T>
T min_0(T a) {
	if (a > 0) return 0;
	return a;
}
ll read() {
	ll u;
	ll k = scanf("%lld", &u);
	return u;
}
ll gcd(ll i, ll j) {
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcd(j % i, i);
}
ll mod_pow(ll x, ll n, ll p) {
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
int a[400000];
bool solve(int t) {
	vector<H>v;
	v.push_back(H{ 1,0 });
	for (int i = 0; i < n; i++) {
		if (v[v.size() - 1].x < a[i]) {
			v.push_back(H{ a[i],1 });
		}
		else {
			while (!v.empty() && v[v.size() - 1].x > a[i]) v.pop_back();
			if (v[v.size() - 1].x == a[i]) v[v.size() - 1].y++;
			else v.push_back(H{ a[i],2 });
		}
		while (v.size() >= 2 && v[v.size() - 1].y == t + 1) {
			int k = v.size();
			if (v[k - 2].x == v[k - 1].x - 1) {
				v[k - 2].y++;
				v.pop_back();
			}
			else {
				k = v[k - 1].x - 1;
				v.pop_back();
				v.push_back(H{ k,1 });
			}
		}
		if (i == 0) v[0].y = 1;
	}
	if (v[0].y > t) return 0;
	return 1;

}
signed main() {
	cin >> n;
	bool b = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0 && a[i - 1] >= a[i]) b = 0;
	}
	if (b) {
		cout << 1 << endl;
		return 0;
	}
	int ng = 1, ok = (1 << 30), t;
	while (abs(ok-ng) > 1) {
		t = (ok+ng) / 2;
		if (solve(t)) ok = t;
		else ng = t;
	}
	cout << ok << endl;
}
