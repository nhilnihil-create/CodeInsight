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

int n, m;
vector<int> vec[100010];
int cnt1, cnt2;
int cnt[100010];

bool dfs(int v, int p, int k) {
	cnt[v] = k;
	if (0 < k)cnt1++;
	else cnt2++;
	for (int i = 0; i < (int)vec[v].size(); i++) {
		if (vec[v][i] == p)continue;
		if (cnt[v] == cnt[vec[v][i]])return false;
		if (cnt[vec[v][i]] == 0 && !dfs(vec[v][i], v, -k))return false;
	}
	return true;
}

signed main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	if (dfs(1, 0, 1))cout << cnt1 * cnt2 - m << endl;
	else cout << n * (n - 1) / 2 - m << endl;
}