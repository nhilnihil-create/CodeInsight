#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000000000000
#define MOD 1000000007
typedef pair<int, int> P;

bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
int mod_pow(int n, int p, int m) {
	if (p == 0) return 1;
	if (p % 2 == 0) {
		int t = mod_pow(n, p / 2, m);
		return (t * t) % m;
	}
	return n * mod_pow(n, p - 1, m) % m;
}
int extGCD(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long d = extGCD(b, a % b, y, x);
	y -= a / b * x;
	return d;
}
int modinv(int a, int m) {
	int b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
int digit(int x) {
	int cnt = 0;
	while (x > 0) {
		cnt += x % 10;
		x /= 10;
	}
	return cnt;
}

int b[200005][22];
int cnt[22];

signed main() {
	int n, ans = 0;
	cin >> n;
	int a[200005];
	rep(i, n) cin >> a[i];
	rep(i, n) {
		rep(j, 21) {
			b[i][j] = a[i] / (1 << j) % 2;
		}
	}
	int r = -1;
	int l = 0;
	for (;;) {
		bool bou = true;
		while (r < n) {
			rep(i, 21) {
				if (cnt[i] > 1) {
					bou = false;
					break;
				}
			}
			if (!bou) break;
			r++;
			rep(i, 21) cnt[i] += b[r][i];
		}
		if (l == n) break;
		ans += r - l;
		rep(i, 21) {
			cnt[i] -= b[l][i];
		}
		l++;
	}
	cout << ans << endl;

	return 0;
}
