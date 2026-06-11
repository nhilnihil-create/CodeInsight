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

string s;
int cnt[30];

signed main() {
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++)cnt[s[i] - 'a']++;
	for (int i = 0; i < 26; i++)if (!cnt[i]) {
		cout << s + char(i + 'a') << endl;
		return 0;
	}
	for (int i = (int)s.size() - 1; i > 0; i--) {
		if (s[i - 1] < s[i]) {
			char mi = 'z';
			for (int j = i; j < 26; j++)if (s[i - 1] < s[j])mi = min(mi, s[j]);
			for (int j = 0; j < i - 1; j++)cout << s[j];
			cout << mi << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}