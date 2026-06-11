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
int kai(int x, int y, int m) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= m;
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

int comb(int x, int y, int m) {
	if (y > x)return 0;
	return kai(x, y, m) * mod_pow(kai(y, y, m), m - 2, m) % m;
}

int k;
int ans = 0, p = 1;

int f(int x) {
	int res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}

signed main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		ans += p;
		cout << ans << endl;
		long double c = (long double)(ans + p) / f(ans + p);
		long double d = (long double)(ans + 2 * p) / f(ans + 2 * p);
		if (c > d)p *= 10;
	}
}
