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
using namespace std;
#define pie 3.141592653589793238462643383279
#define mod 998244353
#define INF 1145141919364364
#define int long long
#define all(vec) vec.begin(),vec.end()
#define P pair<int,int>
#define S second
#define F first

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0)return false;
	}
	return true;
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

int n, a, b, k;
int ans;
int kaii[300010];

int ccomb(int x, int y) {
	return kaii[x] * mod_pow(kaii[x - y], mod - 2, mod) % mod*mod_pow(kaii[y], mod - 2, mod) % mod;
}

signed main() {
	cin >> n >> a >> b >> k;
	kaii[0] = 1;
	for (int i = 1; i <= n+1; i++)kaii[i] = kaii[i - 1] * i%mod;
	for (int i = 0; i <= n; i++) {
		if ((k - a * i) % b != 0 || (k - a * i) / b<0 || (k - a * i) / b>n)continue;
		int j = (k - a * i) / b;
		ans += ccomb(n, i)*ccomb(n, j);
		ans %= mod;
	}
	cout << ans << endl;
}