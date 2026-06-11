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
#include <unordered_map>
#include <cstdio>
using namespace std;
#define pie 3.141592653589793238462643383279
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
int kai(int x, int y, int m) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= m;
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

int comb(int x, int y, int m) {
	if (y > x)return 0;
	return kai(x, y, m) * mod_pow(kai(y, y, m), m - 2, m) % m;
}

int h, w, n;
vector<int> vec[200010];
int ma = 1;

signed main() {
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		vec[x].push_back(y);
	}
	for (int i = 1; i <= h; i++)sort(all(vec[i])), vec[i].push_back(w + 1);
	for (int i = 1; i < h; i++) {
		if (!vec[i + 1].empty() && vec[i + 1][0] <= ma) {
			cout << i << endl;
			return 0;
		}
		if (!(upper_bound(all(vec[i + 1]), ma + 1) - lower_bound(all(vec[i + 1]), ma + 1)))ma++;
	}
	cout << h << endl;
}