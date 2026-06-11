#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18+7)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
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
	return x * y / gcd(x, y);
}
int kai(int x) {
	if (x == 0)return 1;
	return kai(x - 1) * x % mod;
}
int mod_pow(int x, int y, int mod_) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % mod_;
		}
		x = x * x % mod_;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	return kai(x)* mod_pow(kai(x - y), mod - 2, mod) % mod * mod_pow(kai(y), mod - 2, mod) % mod;
}
/*--------Library Zone!--------*/

void no() {
	cout << -1 << endl;
	exit(0);
}
signed main() {
	int n, a, b; cin >> n >> a >> b;
	if (a + b > n + 1)no();
	if ((n - 1) / a >= b)no();
	b -= (n - 1) / a + 1;
	rep(i, a)cout << n - a + i + 1 << " ";
	n -= a;
	while (1) {
		if (n <= 0) {
			cout << endl; return 0;
		}
		stack<int>st; queue<int>que;
		rep(i, a) {
			if (n - a + i + 1 >= 1)que.push(n - a + i + 1);
		}
		rep(i, min(a, b)) {
			int p = que.front(); que.pop(); st.push(p);
		}
		while (!que.empty()) {
			cout << que.front() << " "; que.pop();
		}
		while (!st.empty()) {
			cout << st.top() << " "; st.pop();
		}
		b -= a - 1;
		n -= a;
	}
}