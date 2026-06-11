#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int mx = 1;
	for (int i = 0; i < n; i++) mx *= 3;
	int ans = 0;
	for (int i = 0; i < mx; i++) {
		vector<int> b(n);
		vector<int> c(n);
		int t = i;
		bool ok = false;
		for (int j = 0; j < n; j++) {
			c[j] = t % 3; t /= 3;
			if (c[j] == 0) b[j] = a[j] - 1;
			if (c[j] == 1) b[j] = a[j];
			if (c[j] == 2) b[j] = a[j] + 1;
			if (~b[j] & 1) ok = true;
		}
		if (ok) ans++;
	}
	cout << ans << endl;
	return 0;
}
