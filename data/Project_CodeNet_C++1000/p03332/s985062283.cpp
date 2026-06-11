#include <bits/stdc++.h>
#define int long long
#define double long double
#define endre getchar();getchar();return 0
#define moder 998244353
#define inf 5000000000000000000
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define all(v) v.begin(),v.end()
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())
using namespace std;

bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}
int mod_pow(int x, int y, int mod) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x%mod;
		}
		x = x * x%mod;
		y >>= 1;
	}
	return res;
}
int kai(int x) {
	if (x == 0)return 1;
	return (kai(x - 1)*x) % moder;
}
int comb(int x, int y) {
	return kai(x)*mod_pow(kai(x - y), moder - 2, moder) % moder*mod_pow(kai(y), moder - 2, moder) % moder;
}
struct edge { int to, cost; };
int dx[5] = { 0,1,0,-1 }, dy[5] = { 1,0,-1,0 };
map<int, int>factor(int x) {
	map<int, int>res;
	for (int i = 2; i*i <= x; i++) {
		while (x%i == 0) {
			x /= i;
			res[i]++;
		}
	}
	if (x != 1)res[x]++;
	return res;
}
/*--------Library Zone!--------*/

int n, a, b, k, ans;
int comemo[364364];
void init() {
	comemo[0] = 1;
	REP(i, n + 1) {
		comemo[i] = comemo[i - 1] * i%moder;
	}
}
int solvecomb(int x, int y) {
	return comemo[x] * mod_pow(comemo[x - y], moder - 2, moder) % moder*mod_pow(comemo[y], moder - 2, moder) % moder;
}
signed main() {
	cin >> n >> a >> b >> k;
	init();
	rep(i, n + 1) {
		if ((k - a * i) % b != 0 || (k - a * i) / b > n || (k - a * i) / b < 0)continue;
		int memo = (k - a * i) / b;
		ans += solvecomb(n, i)*solvecomb(n, memo) % moder;
		ans %= moder;
	}
	cout << ans << endl;
	endre;
}
