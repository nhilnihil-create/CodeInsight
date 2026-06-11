#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18+7)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(v) v.begin(),v.end()
#define mkp make_pair
#define mkt make_tuple
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())
using namespace std;

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return false;
	}
	return x > 1;
}
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
int mod_pow(int x, int y) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % mod;
		}
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2) % mod;
}
/*--------Library Zone!--------*/

int n, ans;
char c[364][364];
signed main() {
	cin >> n;
	rep(i, n)rep(j, n)cin >> c[i][j];
	//X
	rep(i, n) {
		char d[364][364];
		rep(j, n)rep(k, n)d[(j + i) % n][k] = c[j][k];
		rep(j, n)rep(k, n) {
			if (d[j][k] != d[k][j])goto ng;
		}
		ans += n - i;
	ng:;
	}
	//Y
	REP(i, n) {
		char d[364][364];
		rep(j, n)rep(k, n)d[j][(k + i) % n] = c[j][k];
		rep(j, n)rep(k, n) {
			if (d[j][k] != d[k][j])goto ng2;
		}
		ans += n - i;
	ng2:;
	}
	cout << ans << endl;
}