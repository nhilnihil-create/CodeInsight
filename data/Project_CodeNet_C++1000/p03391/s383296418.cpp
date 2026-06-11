#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int64_t a[n], b[n];
	{
		bool flg = true;
		for(int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];
			if(a[i] != b[i]) flg = false;
		}
		if(flg) {
			cout << 0 << '\n';
			return 0;
		}
	}
	int64_t ans = 0, mini = 1e18;
	for(int i = 0; i < n; ++i) {
		ans += a[i];
		if(a[i] > b[i]) {
			mini = min(mini, b[i]);
		}
	}
	cout << ans - mini << '\n';
	return 0;
}