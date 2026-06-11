#include <bits/stdc++.h>

using namespace std;

#define ll long long

signed main() {
	int k; cin >> k;
	vector<int> a(k);
	for (int i = 0; i < k; ++i)
		cin >> a[i];

	if (a[k - 1] != 2) {
		cout << -1 << endl;
		exit(0);
	}

	ll s = 2, m = 2;
	for (int i = k - 1; i >= 0; --i) {
		int ai = a[i];
		// nx_s := s以上の最小のaiの倍数
		ll nx_s = ((s - 1) / ai + 1) * ai;
		// nx_m := m以下の最大のaiの倍数 + (ai - 1)
		ll nx_m = (m / ai * ai) + ai - 1;
		if (nx_m < nx_s) {
			cout << -1 << endl;
			exit(0);
		}
		s = nx_s; m = nx_m;
	}

	cout << s << " " << m << endl;

	return 0;
}