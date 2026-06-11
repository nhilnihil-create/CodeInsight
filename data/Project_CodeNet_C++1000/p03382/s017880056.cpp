// author: Saman Mahdanian
#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 10;
const int MOD = 1e9 + 7;

int _sum (int, int);
int _mul (int, int);
int _pow (int, int);

int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a, a + n);

	for (int i = 0; i < n; i++)
		b[i] = min(a[n - 1] - a[i], a[i]);
	cout << a[n - 1] << ' ' << a[max_element(b, b + n) - b] << endl;
}

// int choose (int r, int k) {
// 	return _mul (f[k], _mul(inv[r], inv[k - r]));
// }

int _sum (int a, int b) {
	return a + b - (a + b >= MOD? MOD : 0);
}

int _mul (int a, int b) {
	return 1LL * a * b % MOD;
}

int _pow (int a, int b) {
	if (!b) 
		return 1;
	int res = _pow (a, b >> 1);
	res = _mul (res, res);
	if (b & 1)
		res = _mul (res, a);
	return res;
}

// SamMHD :: Jun27-2019 :: Another Day with Shayan...