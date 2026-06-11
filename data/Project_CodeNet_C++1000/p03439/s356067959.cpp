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
#include <string.h>
using namespace std;
#define pie 3.141592653589793238462643383279
#define mod 998244353
#define int long long
#define INF 1145141919810364364
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

signed main() {
	cin >> n;
	cout << 0 << endl;
	cin >> s;
	int mi = 0, ma = n;
	int x = 0;
	if (s == "Vacant")return 0;
	if (s == "Male") x = 1;
	else x = 2;
	while (1) {
		int md = (mi + ma) / 2;
		cout << md << endl;
		cin >> s;
		if (s == "Vacant")return 0;
		if (s == "Male") {
			if (x == 1) {
				if ((md - mi) % 2)ma = md;
				else {
					mi = md;
					x = 1;
				}
			}
			else {
				if ((md - mi) % 2) {
					mi = md;
					x = 1;
				}
				else ma = md;
			}
		}
		else {
			if (x == 1) {
				if ((md - mi) % 2) {
					mi = md;
					x = 2;
				}
				else ma = md;
			}
			else {
				if ((md - mi) % 2)ma = md;
				else {
					mi = md;
					x = 2;
				}
			}
		}
	}
}