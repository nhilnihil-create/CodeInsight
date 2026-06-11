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

int n, k, q, a[2010];
vector<int> vec;
int ans = INF;

signed main() {
	cin >> n >> k >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		vec.push_back(a[i]);
	}
	sort(all(vec));
	for (int i = 0; i <= n - q; i++) {
		int cnt = 0, cnt2 = 0;
		priority_queue<int, vector<int>, greater<int>> que, que2;
		for (int j = 0; j < n; j++) {
			if (a[j] < vec[i]) {
				cnt = 0;
				while (!que.empty())que.pop();
			}
			else {
				cnt++;
				que.push(a[j]);
				if (k <= cnt) {
					cnt2++;
					que2.push(que.top());
					que.pop();
				}
			}
		}
		if (q <= cnt2) {
			int ma = 0;
			for (int j = 0; j < q; j++) {
				ma = max(ma, que2.top());
				que2.pop();
				
			}
			ans = min(ans, ma - vec[i]);
		}
	}
	cout << ans << endl;
}
