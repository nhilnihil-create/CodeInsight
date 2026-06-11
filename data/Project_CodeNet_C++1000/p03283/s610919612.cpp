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
using namespace std;
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define int long long
#define P pair<int,int>
#define all(vec) vec.begin(),vec.end()

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}

int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}

int s = 1;
vector<int> dat, lazy;

void init(int n_) {
	while (s < n_)s *= 2;
	dat.resize(2 * s - 1);
	lazy.resize(2 * s - 1);
}

void eval(int k, int l, int r) {
	if (lazy[k]) {
		dat[k] += lazy[k];
		if (r - l > 1) {
			lazy[2 * k + 1] += lazy[k] / 2;
			lazy[2 * k + 2] += lazy[k] / 2;
		}
		lazy[k] = 0;
	}
}

void add(int a, int b, int x, int k = 0, int l = 0, int r = s) {
	eval(k, l, r);
	if (r <= a || b <= l)return;
	if (a <= l && r <= b) {
		lazy[k] += x * (r - l);
		eval(k, l, r);
		return;
	}
	add(a, b, x, 2 * k + 1, l, (l + r) / 2);
	add(a, b, x, 2 * k + 2, (l + r) / 2, r);
	dat[k] = dat[2 * k + 1] + dat[2 * k + 2];
}

int query(int a, int b, int k = 0, int l = 0, int r = s) {
	if (r <= a || b <= l)return 0;
	eval(k, l, r);
	if (a <= l && r <= b)return dat[k];
	int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
	int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
	return vl + vr;
}

int n, m, q, l[200010], r[200010], a[100010], b[100010];
vector<int> vec;
vector<pair<P, P>> ve;
int ans[100010];

signed main() {
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
		vec.push_back(l[i]);
		vec.push_back(r[i]);
		vec.push_back(l[i] + 1);
	}
	for (int i = 0; i < q; i++) {
		cin >> a[i] >> b[i];
		vec.push_back(a[i]);
		vec.push_back(b[i]);
		vec.push_back(a[i] + 1);
	}
	sort(all(vec));
	vec.erase(unique(all(vec)), vec.end());
	n = (int)vec.size();
	init(n);
	for (int i = 0; i < m; i++) {
		l[i] = lower_bound(all(vec), l[i]) - vec.begin();
		r[i] = lower_bound(all(vec), r[i]) - vec.begin();
		ve.push_back(make_pair(make_pair(r[i], 1), make_pair(l[i], 0)));
	}
	for (int i = 0; i < q; i++) {
		a[i] = lower_bound(all(vec), a[i]) - vec.begin();
		b[i] = lower_bound(all(vec), b[i]) - vec.begin();
		ve.push_back(make_pair(make_pair(b[i], 2), make_pair(a[i], i)));
	}
	sort(all(ve));
	for (int i = 0; i < (int)ve.size(); i++) {
		if (ve[i].first.second == 1)add(0, ve[i].second.first + 1, 1);
		else {
			int x = query(ve[i].second.first, ve[i].second.first + 1);
			ans[ve[i].second.second] = x;
		}
	}
	for (int i = 0; i < q; i++)cout << ans[i] << endl;
}