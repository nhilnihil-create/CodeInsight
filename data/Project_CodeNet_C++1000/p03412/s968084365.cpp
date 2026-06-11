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
#define mod 998244353
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

int n, a[200010], b[200010];
int ans;

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++)cin >> b[i];
	b[n] = 10000000000;
	for (int i = 28; i >= 0; i--) {
		for (int j = 0; j < n; j++)a[j] %= (1 << (i + 1)), b[j] %= (1 << (i + 1));
		sort(b, b + n);
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			int p = lower_bound(b, b + n + 1, (1 << i) - a[j]) - b;
			int q = lower_bound(b, b + n + 1, 2 * (1 << i) - a[j]) - b;
			cnt += q - p;
			p = lower_bound(b, b + n + 1, 3 * (1 << i) - a[j]) - b;
			q = lower_bound(b, b + n + 1, 4 * (1 << i) - a[j]) - b;
			cnt += q - p;
		}
		if (cnt % 2)ans += (1 << i);
	}
	cout << ans << endl;
}