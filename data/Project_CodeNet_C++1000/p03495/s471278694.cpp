#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int>a(n, 0);

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		a[tmp-1]++;
	}
	int cnt = 0;
	for (auto&& x : a) {
		if (x)cnt++;
	}

	if (cnt <= k)cout << 0 << endl;
	else {
		int ans = 0;
		sort(a.begin(), a.end());
		for (auto&& x : a) {
			if (x) {
				ans += x;
				cnt--;
			}
			if (cnt == k) {
				cout << ans << endl;
				return 0;
			}
		}
	}

	return 0;
}