#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
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
using namespace std;
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define INF 1145141919810364364
#define int long long
#define all(vec) vec.begin(),vec.end()
#define P pair<int,int>

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
pair<P, P> a[1010];
int d[1010][20010];

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first.second >> a[i].second.first >> a[i].second.second;
		a[i].first.first = a[i].first.second + a[i].second.first;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 20000; j++)d[i + 1][j] = d[i][j];
		for (int j = 0; j <= a[i].second.first; j++)d[i + 1][j + a[i].first.second] = max(d[i + 1][j + a[i].first.second], d[i][j] + a[i].second.second);
	}
	int ans = 0;
	for (int i = 0; i <= 20000; i++)ans = max(ans, d[n][i]);
	cout << ans << endl;
}