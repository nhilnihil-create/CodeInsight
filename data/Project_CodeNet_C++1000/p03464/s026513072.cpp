#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main() {
	int k; cin >> k;
	vector<ll> a(k);
	for (auto&& x : a)cin >> x;
	reverse(a.begin(), a.end());

	ll l = 2, r = 2;
	for (int i = 0; i < k; i++) {
		l = (l + a[i] - 1) / a[i] * a[i];
		r = ((r / a[i]) + 1) * a[i] - 1;
		if (l > r) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << l << ' ' << r << endl;
}