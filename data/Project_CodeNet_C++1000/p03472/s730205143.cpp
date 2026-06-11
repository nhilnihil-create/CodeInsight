#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t n, h;
	cin >> n >> h;
	vector<double_t> a(n);
	vector<double_t> b(n);
	for (size_t i = 0; i < n; i++)cin >> a.at(i) >> b.at(i);
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	int64_t ans = 0;
	for (size_t i = 0; i < n; i++) {
		if (b.at(i) > a.at(0)) {
			h -= b.at(i);
			ans++;
		}
		if (h <= 0) {
			cout << ans << endl;
			return 0;
		}
	}
	ans += ceil(h / a.at(0));
	cout << ans << endl;
}