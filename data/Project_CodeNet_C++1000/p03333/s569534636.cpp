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

int n;
int l[100010], r[100010];
set<P> stl, str;
int ans1, ans2;

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		stl.insert(make_pair(l[i], i));
		str.insert(make_pair(r[i], i));
	}
	int k = 0;
	while (!stl.empty()) {
		P x = *stl.rbegin();
		if (x.first <= k)break;
		ans1 += x.first - k;
		k = x.first;
		int p = x.second;
		stl.erase(x);
		str.erase(make_pair(r[p], p));
		if (str.empty())break;
		P y = *str.begin();
		if (k <= y.first)break;
		ans1 += k - y.first;
		k = y.first;
		p = y.second;
		str.erase(y);
		stl.erase(make_pair(l[p], p));
	}
	ans1 += abs(k);
	k = 0;
	stl.clear(); str.clear();
	for (int i = 0; i < n; i++) {
		stl.insert(make_pair(l[i], i));
		str.insert(make_pair(r[i], i));
	}
	while (!stl.empty()) {
		P y = *str.begin();
		if (k <= y.first)break;
		ans2 += k - y.first;
		k = y.first;
		int p = y.second;
		str.erase(y);
		stl.erase(make_pair(l[p], p));
		if (str.empty())break;
		P x = *stl.rbegin();
		if (x.first <= k)break;
		ans2 += x.first - k;
		k = x.first;
		p = x.second;
		stl.erase(x);
		str.erase(make_pair(r[p], p));
	}
	ans2 += abs(k);
	cout << max(ans1, ans2) << endl;
}