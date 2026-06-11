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

int n, a[200010];

bool ok(int k) {
	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		if (a[i - 1] < a[i])continue;
		if (k == 1)return false;
		auto p = mp.upper_bound(a[i]);
		while (p != mp.end()) {
			auto q = p;
			p++;
			mp.erase(q);
		}
		int x = a[i];
		while (1) {
			if (mp[x] != k - 1) {
				mp[x]++;
				break;
			}
			if (x == 1) return false;
			mp[x] = 0;
			x--;
		}
	}
	return true;
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	int mi = 0, ma = n;
	while (ma - mi > 1) {
		int md = (mi + ma) / 2;
		if (ok(md))ma = md;
		else mi = md;
	}
	cout << ma << endl;
}