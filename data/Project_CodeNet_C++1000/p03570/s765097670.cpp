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
const ll mod = 0;
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
template<typename T, typename U>
void chmin(T &a, U b) {
	if (a > b) a = b;
}
template<typename T, typename U>
void chmax(T &a, U b) {
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
	scanf("%lld", &u);
	return u;
}
ll gcd(ll i, ll j) {
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcd(j%i, i);
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
//#define int unsigned long long
//----------------------------------------------------
string s;
int dp[300000];
int bit[1 << 26];
signed main() {
	cin >> s;
	for (int i = 1; i < 1ll << 26; i++) {
		bit[i] = inf;
	}
	ll res = 0;
	for (int i = 0; i < s.size(); i++) {
		int t = (int)(s[i] - 'a');
		res ^= 1 << t;
		int sum = bit[res];
		for (int j = 0; j < 26; j++) {
			sum = min(sum, bit[res ^ (1 << j)]);
		}
		bit[res] = min(bit[res], sum + 1);
		dp[i] = sum + 1;
	}
	cout << dp[s.size() - 1] << endl;
}