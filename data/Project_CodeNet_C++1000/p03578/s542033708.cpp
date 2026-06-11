#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
#include <random>
#include <string.h>
#include <cmath>
#include <unordered_map>
#include <cstdio>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long ll;

ll gcd(ll x, ll y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y)*y;
}
ll kai(ll x, ll y, ll m) {
	ll res = 1;
	for (ll i = x - y + 1; i <= x; i++) {
		res *= i; res %= m;
	}
	return res;
}
ll mod_pow(ll x, ll y, ll m) {
	ll res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}

ll comb(ll x, ll y, ll m) {
	if (y > x)return 0;
	return kai(x, y, m) * mod_pow(kai(y, y, m), m - 2, m) % m;
}

int n, m;
multiset<int> st;

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		st.insert(a);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		if (st.lower_bound(a) == st.upper_bound(a)) {
			cout << "NO" << endl;
			return 0;
		}
		st.erase(st.lower_bound(a));
	}
	cout << "YES" << endl;
}