#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int>x(n);
	for (int i = 0; i < n; i++)cin >> x.at(i);
	ll ans = 1e18;
	for (int i = 0; i <= n - k; i++) {
		int l = x.at(0+i);
		int r = x.at(k - 1+i);
		ll res = 0;
		if (r <= 0)res = abs(l);
		else if (l >= 0)res = r;
		else res = min(r - l + abs(l), r - l + r);
		ans = min(ans, res);
		//cout << l << " " << r << " " << res << endl;
	}
	cout << ans << endl;
}