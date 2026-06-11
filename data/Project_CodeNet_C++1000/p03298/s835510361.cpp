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
string s;
map<pair<string, string>, int> mp;
int ans;

signed main() {
	cin >> n >> s;
	for (int i = 0; i < (1 << n); i++) {
		string t1 = "", t2 = "";
		for (int j = 0; j < n; j++)if (i&(1 << j))t1 += s[j];
		for (int j = n - 1; j >= 0; j--)if (!(i&(1 << j)))t2 += s[j];
		mp[make_pair(t1, t2)]++;
	}
	for (int i = 0; i < (1 << n); i++) {
		string t1 = "", t2 = "";
		for (int j = 0; j < n; j++)if (i&(1 << j))t1 += s[n + j];
		for (int j = n - 1; j >= 0; j--)if (!(i&(1 << j)))t2 += s[n + j];
		ans += mp[make_pair(t2, t1)];
	}
	cout << ans << endl;
}