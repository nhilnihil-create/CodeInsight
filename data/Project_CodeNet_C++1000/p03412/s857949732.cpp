#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <climits>
#include <numeric>
#include<stdio.h>
#include <queue>
#include <iomanip>
#include <float.h>
#include <set>
#include<functional>
#include <stack>
#include <time.h>
#include <climits>
#include <bitset>
#include <cmath>
using namespace std;
long long gcd(long long a, long long b) {
	if (a < b) gcd(b, a);
	long long  r;
	while ((r = a%b)) {
		a = b;
		b = r;
	}
	return b;
}
long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

long long modinv(long long a, long long mod) {
	long long b = mod, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t*b; swap(a, b);
		u -= t*v; swap(u, v);
	}
	u %= mod;
	if (u < 0) u += mod;
	return u;
}
inline long long mod(long long a, long long m) {
	return (a % m + m) % m;
}

// 拡張 Euclid の互除法
// ap + bq = gcd(a, b) となる (p, q) を求め、d = gcd(a, b) をリターンします
long long extGcd(long long a, long long b, long long &p, long long &q) {
	if (b == 0) { p = 1; q = 0; return a; }
	long long d = extGcd(b, a%b, q, p);
	q -= a / b * p;
	return d;
}

// 中国剰余定理
// リターン値を (r, m) とすると解は x ≡ r (mod. m)
// 解なしの場合は (0, -1) をリターン
//amari,mod,amari,mod
pair<long long, long long> ChineseRem(long long b1, long long m1, long long b2, long long m2) {
	long long p, q;
	long long d = extGcd(m1, m2, p, q); // p is inv of m1/d (mod. m2/d)
	if ((b2 - b1) % d != 0) return make_pair(0, -1);
	long long m = m1 * (m2 / d); // lcm of (m1, m2)
	long long tmp = (b2 - b1) / d * p % (m2 / d);
	long long r = mod(b1 + m1 * tmp, m);
	return make_pair(r, m);
}
typedef pair<long long,long long>p;
#define int long long
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[200004];
	int b[200004];
	int bb[200004];
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < n; j++) {
		cin >> b[j];
	}
	for (int t = 29; t >= 0; t--) {
		long long k = 1;
		for (int i = 0; i < t; i++) {
			k *= 2;
		}
		for (int i = 0; i < n; i++) {
			bb[i] = b[i] % (k*2);
			a[i] %= (k * 2);
		}
		sort(bb, bb + n);
		bb[n] = LLONG_MAX;
		long long cnt = 0;
		if (t == 0) {
			int x = 10;
		}
		for (int i = 0; i < n; i++) {
			cnt += lower_bound(bb, bb + n+1, 2*k - a[i]) - lower_bound(bb, bb + n+1,  k - a[i]);
			cnt %= 2;
			cnt += lower_bound(bb, bb + n+1, k * 4 - a[i]) - lower_bound(bb, bb + n+1, 3 * k - a[i]);
			cnt %= 2;
		}
		ans += (cnt % 2)*k;
	}
	cout << ans;
}
