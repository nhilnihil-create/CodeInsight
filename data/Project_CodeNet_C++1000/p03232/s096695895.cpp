#include <bits/stdc++.h>

using namespace std;

inline int inv(int a, int m) {
	int i = 1, j = 0;
	for (int b = m; a > 1; swap(i, j), swap(a, b)) {
		j = (j + b / a * long(m - i)) % m;
		b %= a;
	}
	return i;
}
int h[111111];
int main() {
	int n;
	cin >> n;
	int p = 1e9 + 7, f = 1;
	for (int i = 0; i < n; i++) {
		h[i + 1] = (h[i] + inv(i + 1, p)) % p;
		f = f * long(i + 1) % p;
	}
	long r = 0;
	for (int i = 0; i < n; i++) {
		long a;
		scanf("%ld", &a);
		r = (r + a * (h[i + 1] + h[n - i] - 1)) % p;
	}
	cout << r * f%p << endl;
	return 0;
}
