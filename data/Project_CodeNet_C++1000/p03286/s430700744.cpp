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
#define mod 1000000007
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

string solve(int x) {
	string res = "";
	if (x % 2)res = '1';
	else res = '0';
	int cnt = 2;
	for (int k = 4; cnt <= x; k *= 4) {
		if (cnt <= x % k&&x%k < cnt + k / 2)res = '1' + res;
		else res = '0' + res;
		if (cnt <= x % (2 * k) && x % (2 * k) < cnt + k)res = '1' + res;
		else res = '0' + res;
		cnt += k;
	}
	return res;
}

int n;

signed main() {
	cin >> n;
	if (0 <= n)cout << solve(n) << endl;
	else {
		string ans = solve(n*-2);
		for (int i = 0; i < (int)ans.size() - 1; i++)cout << ans[i];
		cout << endl;
	}
}