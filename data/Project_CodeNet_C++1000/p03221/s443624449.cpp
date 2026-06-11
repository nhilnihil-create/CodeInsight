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

void f(int x) {
	int cnt = 0;
	int k = x;
	while (k) {
		cnt++;
		k /= 10;
	}
	for (int i = 0; i < 6 - cnt; i++)cout << 0;
	cout << x;
}

int n, m, a[100010], b[100010];
vector<int> vec[100010];

signed main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		vec[a[i]].push_back(b[i]);
	}
	for (int i = 1; i <= n; i++)sort(all(vec[i]));
	for (int i = 0; i < m; i++) {
		f(a[i]);
		f(lower_bound(all(vec[a[i]]), b[i]) - vec[a[i]].begin() + 1);
		cout << endl;
	}
}