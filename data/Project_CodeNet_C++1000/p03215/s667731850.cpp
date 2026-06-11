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

int n, k, a[1010];
int cum[1010];
vector<int> vec, vec2;
int ans;

signed main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cum[i] = cum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++)for (int j = i; j <= n; j++)vec.push_back(cum[j] - cum[i - 1]);
	for (int i = 39; i >= 0; i--) {
		vec2.clear();
		for (int j = 0; j < (int)vec.size(); j++)if (vec[j] & (1LL << i))vec2.push_back(vec[j]);
		if (k <= (int)vec2.size()) {
			vec.clear();
			vec = vec2;
			ans += (1LL << i);
		}
	}
	cout << ans << endl;
}