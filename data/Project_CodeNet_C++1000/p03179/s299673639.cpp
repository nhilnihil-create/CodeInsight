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
string s;
int d[3010][3010];

signed main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++)d[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		if (s[i - 2] == '<') {
			int cnt = d[i - 1][n - i + 1];
			for (int j = n - i; j >= 0; j--) {
				d[i][j] = cnt;
				cnt = (cnt + d[i - 1][j]) % mod;
			}
		}
		else {
			int cnt = d[i - 1][0];
			for (int j = 0; j <= n - i; j++) {
				d[i][j] = cnt;
				cnt = (cnt + d[i - 1][j + 1]) % mod;
			}
		}
	}
	cout << d[n][0] << endl;
}