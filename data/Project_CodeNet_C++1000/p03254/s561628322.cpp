#include <bits/stdc++.h>
using namespace std;
int main() {
	int64_t n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
	}
	sort(a.begin(), a.end());
	int ans = 0;
	int i = 0;
	for (int j = 0; j < n; j++) {
		int y = a.at(j);
		if (y <= x) {
			x -= y;
			ans++;
		}
		else {
			cout << ans << endl;
			return 0;
		}
	}
	if (x > 0)ans--;
	cout << ans << endl;
}