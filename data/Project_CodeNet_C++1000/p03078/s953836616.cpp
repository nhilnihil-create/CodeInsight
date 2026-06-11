#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


int main(void) {
	int x, y, z, i, j, k;
	ll a[1003], b[1003], c[1003];
	vector<ll> w;

	cin >> x >> y >> z >> k;
	for (i = 0; i < x; i++) cin >> a[i];
	for (i = 0; i < y; i++) cin >> b[i];
	for (i = 0; i < z; i++) cin >> c[i];

	for (i = 0; i < y; i++) for (j = 0; j < z; j++) {
		w.push_back(b[i] + c[j]);
	}

	sort(w.begin(), w.end());

	int sn;
	ll l, r, mid;
	l = 0;
	r = 1e18;
	while (r - l > 1) {
		mid = (l + r) / 2;
		sn = 0;
		for (i = 0; i < x; i++) {
			sn += w.end() - lower_bound(w.begin(), w.end(), mid - a[i]);
		}
		if (sn >= k) l = mid;
		else r = mid;
	}

	ll t = l;

	vector<ll> ans;
	vector<ll>::iterator ite;
	for (i = 0; i < x; i++) {
		ite = lower_bound(w.begin(), w.end(), t - a[i]);
		while (ite != w.end()) {
			ans.push_back(*ite + a[i]);
			ite++;
		}
	}

	sort(ans.begin(), ans.end(), greater<ll>());

	for (i = 0; i < k; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}