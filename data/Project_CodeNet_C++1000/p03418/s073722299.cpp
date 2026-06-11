#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
	cin >> n >> k;

	if (k == 0) {
		cout << (long long) n * n << endl;
		return 0;
	}
	long long rv = 0;

	for (int b = k + 1, q, r; b <= n; b++) {
		q = n / b, r = n % b;
		rv += (long long) q * (b - k) + max(0, r + 1 - k);
	}
	cout << rv << endl;
}
