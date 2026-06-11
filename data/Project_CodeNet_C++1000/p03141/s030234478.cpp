#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	vector<pair<int, int>> x(n);
	for (int i = 0; i < n; i++) {
		x[i].first = a[i] + b[i];
		x[i].second = i;
	}
	sort(x.begin(), x.end(), greater<pair<int, int>>());
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int idx = x[i].second;
		if (i & 1) {
			ans -= b[idx];
		} else {
			ans += a[idx];
		}
	}
	cout << ans << endl;
	return 0;
}