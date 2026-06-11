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

string s, t;
int p[30];

signed main() {
	cin >> s >> t;
	fill(p, p + 30, 30);
	for (int i = 0; i < (int)s.size(); i++) {
		int x = s[i] - 'a';
		int y = t[i] - 'a';
		if (p[x] < 26) {
			if (p[x] != y) {
				cout << "No" << endl;
				return 0;
			}
		}
		else p[x] = y;
	}
	for (int i = 0; i < 26; i++)for (int j = i + 1; j < 26; j++)if (p[i] == p[j] && p[i] != 30) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
}