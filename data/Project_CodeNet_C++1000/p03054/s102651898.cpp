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
#define int long long
#define INF 1145141919810364364
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

int h, w, n, x, y;
string s, t;

signed main() {
	cin >> h >> w >> n >> y >> x >> s >> t;
	int xmi = x, xma = x , ymi = y, yma = y;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L')xmi--;
		else if (s[i] == 'R')xma++;
		else if (s[i] == 'U')ymi--;
		else yma++;
		if (xmi <= 0 || w < xma || ymi <= 0 || h < yma) {
			cout << "NO" << endl;
			return 0;
		}
		if (t[i] == 'L')xma = max(xma - 1, (int)1);
		else if (t[i] == 'R')xmi = min(xmi + 1, w);
		else if (t[i] == 'U')yma = max(yma - 1, (int)1);
		else ymi = min(ymi + 1, h);
	}
	cout << "YES" << endl;
}