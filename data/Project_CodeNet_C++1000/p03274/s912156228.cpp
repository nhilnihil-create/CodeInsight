#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, k;
	long long x[100000];
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	long long ans = LLONG_MAX;

	for (int i = 0; i < n - k + 1; ++i) {
		ans = min(ans, min(abs(x[i]), abs(x[k + i - 1])) + abs ( x[k + i - 1] - x[i]));
	}

	cout << ans << endl;
	return 0;
}