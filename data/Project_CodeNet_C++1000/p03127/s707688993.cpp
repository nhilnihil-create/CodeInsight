#include "bits/stdc++.h"
using namespace std;

int gcd(int x, int y) {
	if (x < y)gcd(y, x);
	if (y == 0)return x;
	return gcd(y, x % y);
}

int main() {
	int n, a[100000];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = a[0];
	for (int i = 0; i < n - 1; ++i) {
		ans = gcd(ans, a[i + 1]);
	}

	cout << ans << endl;

	return 0;
}