#include <bits/stdc++.h>
using namespace std;
 
const int N = 3e5 + 7;

long long n, k, f[N], M = 998244353;

long long power(long long a, long long b) {
	if (b == 0)
		return 1;
	long long t = power(a, b / 2);
	t = (t * t) % M;
	if (b % 2)
		t = (t * a) % M;
	return t;
}

long long chs(long long a, long long b) {
	if (a > b)
		return 0;
	long long t = f[b];
	t = (t * power(f[a], M - 2)) % M;
	t = (t * power(f[b - a], M - 2)) % M;
	return t;
}


long long a, b;

int main() {
	f[0] = 1;
	for (long long i = 1; i < N; i++)
		f[i] = (f[i - 1] * i) % M;
	cin >> n >> a >> b >> k;
	long long res = 0;
	for (long long x = 0; x <= n; x++) {
		long long tmp = k - a * x;
		if (tmp % b || tmp < 0)
			continue;
		long long y = tmp / b;
		if (x > n || y > n)
			continue;
		res = (res + chs(x, n) * chs(y, n)) % M;
	}
	cout << res;


	return 0;
}
