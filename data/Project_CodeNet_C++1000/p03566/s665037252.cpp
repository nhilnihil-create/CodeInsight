#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define mod 998244353
#define inf (int)(3e18)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P std::pair<int,int>
#define PiP std::pair<int,std::pair<int,int>>
#define all(v) v.begin(),v.end()
#define mkp std::make_pair
#define prique(T) std::priority_queue<T,vector<T>,greater<T>>
using namespace std;
template<class T> inline void chmax(T& a, T b) { a = std::max(a, b); }
template<class T> inline void chmin(T& a, T b) { a = std::min(a, b); }

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return false;
	}
	return x != 1;
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
int get_rand(int MIN, int MAX) {
	std::random_device rnd;
	std::mt19937 mt32(rnd());
	std::uniform_int_distribution<int>engine(MIN, MAX);
	return engine(mt32);
}
/*--------Library Zone!--------*/

int n, t[105];
map<double, double>v;
signed main() {
	cin >> n;
	rep(i, n) {
		int a; cin >> a;
		t[i] += a;
		t[i + 1] += t[i];
	}
	rep(i, t[n]) {
		v[i] = inf;
		v[i + 0.5] = inf;
	}
	rep(i, n) {
		double a; cin >> a;
		for (double j = (i ? t[i - 1] : 0); j <= t[i]; j += 0.5) {
			chmin(v[j], a);
		}
	}
	v[0.0] = 0;
	v[t[n]] = 0;
	for (double i = 20000; i > 0.; i -= 0.5) {
		chmin(v[i - 0.5], v[i] + 0.5);
	}
	double ans = 0;
	double st = 0, sttaka = 0;
	int jyotai = 0;
	double now = 0;
	for (double i = 0; i <= t[n]; i += 0.5) {
		now = min(now + 0.5, v[i]);
		if (jyotai == 0 && now >= v[i + 0.5]) {
			ans += (i - st) * sttaka + (i - st) * (now - sttaka) / 2;
			st = i, sttaka = now;
			if (now == v[i + 0.5])jyotai = 1;
			else jyotai = 2;
		}
		if (jyotai == 1 && now != v[i + 0.5]) {
			ans += (i - st) * now;
			st = i, sttaka = now;
			if (now < v[i + 0.5])jyotai = 0;
			else jyotai = 2;
		}
		if (jyotai == 2 && now <= v[i + 0.5]) {
			ans += (i - st) * now + (i - st) * (sttaka - now) / 2;
			st = i; sttaka = now;
			if (now == v[i + 0.5])jyotai = 1;
			else jyotai = 0;
		}
	}
	printf("%.12lf\n", ans);
}
