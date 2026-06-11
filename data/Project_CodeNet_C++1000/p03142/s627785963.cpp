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
#define mod 1000000007
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

int n, m, a[100010], b[100010];
vector<int> vec[100010], vec2[100010];
int cnt[100010];
stack<int> st;
int p[100010];

signed main() {
	cin >> n >> m;
	for (int i = 0; i < n + m - 1; i++) {
		cin >> a[i] >> b[i];
		vec[a[i]].push_back(b[i]);
		vec2[b[i]].push_back(a[i]);
		cnt[b[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!cnt[i]) {
			st.push(i);
			break;
		}
	}
	int k = 0;
	while ((int)st.size()) {
		int s = st.top(); st.pop();
		k++;
		p[s] = k;
		for (int i = 0; i < (int)vec[s].size(); i++) {
			cnt[vec[s][i]]--;
			if (!cnt[vec[s][i]])st.push(vec[s][i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		int ans = 0, ma = 0;
		for (int j = 0; j < (int)vec2[i].size(); j++) {
			if (ma < p[vec2[i][j]]) {
				ma = p[vec2[i][j]];
				ans = vec2[i][j];
			}
		}
		cout << ans << endl;
	}
}