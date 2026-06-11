#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	int l = 1, r = 1e9;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (1LL * mid * mid < 1LL * a * b) l = mid;
		else r = mid - 1;
	}
	cout << l + (1LL * a * b - 1) / (l + 1) - (a <= l) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t; while (t--) solve();
}