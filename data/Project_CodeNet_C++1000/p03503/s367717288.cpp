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
bool bl[110][10];
int p[110][15];
int ans = -10000000000;

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++)for (int j = 0; j < 10; j++) {
		int a; cin >> a;
		if (a)bl[i][j] = true;
	}
	for (int i = 1; i <= n; i++)for (int j = 0; j <= 10; j++)cin >> p[i][j];
	for (int i = 1; i < 1024; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			int cnt2 = 0;
			for (int k = 0; k < 10; k++)if (bl[j][k] && (i&(1 << k)))cnt2++;
			cnt += p[j][cnt2];
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}
