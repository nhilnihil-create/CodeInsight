#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
#include<stack>
#include<time.h>
#define rep(i,n)for(int i=0;i<n;i++)
#define int long long
#define ggr getchar();getchar();return 0;
#define prique priority_queue
#define mod 1000000007
#define inf 1e15
#define key 1e9
using namespace std;
typedef pair<int, int>P;
void yes() { cout << "Yay!" << endl; }
void no() { cout << ":(" << endl; }
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
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
	while (y) {
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
	return kai(x, y)* mod_pow(kai(y, y), mod - 2, mod) % mod;
}
struct edge { int to, cost; };
int k;
int a[114514];
signed main() {
	cin >> k;
	rep(i, k)cin >> a[i];
	int l = 2, r = inf, mid;
	while (r - l > 1) {
		mid = (l + r) / 2;
		int s = mid;
		rep(i, k)s = s / a[i] * a[i];
		if (s > 2)r = mid;
		else l = mid;
	}
	int nl = 1, nr = inf, nm;
	while (nr - nl > 1) {
		nm = (nl + nr) / 2;
		int ns = nm;
		rep(i, k)ns = ns / a[i] * a[i];
		if (ns >= 2)nr = nm;
		else nl = nm;
	}
	int ml = nl + 1, mr = l;
	rep(i, k) {
		ml = ml / a[i] * a[i];
		mr = mr / a[i] * a[i];
	}
	if (ml != 2 || mr != 2)puts("-1");
	else cout << nl + 1 << " " << l << endl;
	ggr
}
