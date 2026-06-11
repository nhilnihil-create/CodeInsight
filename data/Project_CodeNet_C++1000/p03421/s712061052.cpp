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

int n, a, b;
int cnt;
int ans[300010];

signed main() {
	cin >> n >> a >> b;
	if (n + 1 < a + b || a * b < n) {
		cout << -1 << endl;
		return 0;
	}
	cnt = b;
	for (int i = 1; i <= n; i++) {
		int x = min(a, n - i + 1 - cnt + 1);
		int s = (n - i + 1) * 2 - x + 1;
		for (int j = i; j < i + x; j++)ans[j] = s - (n - j + 1);
		i += x - 1;
		cnt--;
	}
	for (int i = 1; i <= n; i++)cout << ans[i] << " ";
	cout << endl;
}