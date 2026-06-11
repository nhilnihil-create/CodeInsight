#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (k == n) {
		cout << 1 << endl;
		return 0;
	}
	int ans = 1;
	int tmp = k;
	while (tmp < n) {
		tmp += k - 1;
		ans++;
	}
	cout << ans << endl;
	return 0;
}