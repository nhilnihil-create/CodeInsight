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
#include <functional>
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

string s;
int d[70000000];
int a[200010];

signed main() {
	std::random_device rnd;
	std::mt19937_64 mt(rnd());
	cin >> s;
	int n = (int)s.size();
	for (int i = 1; i <= n; i++)a[i] = a[i - 1] ^ (1 << (s[i - 1] - 'a'));
	fill(d + 1, d + 70000000, 1000000000);
	for (int i = 1; i <= n; i++) {
		int mi = d[a[i]];
		for (int j = 0; j < 26; j++)mi = min(mi, d[a[i] ^ (1 << j)]);
		if (i == n)d[a[i]] = mi + 1;
		else d[a[i]] = min(d[a[i]], mi + 1);
	}
	cout << d[a[n]] << endl;
}