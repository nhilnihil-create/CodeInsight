#include <bits/stdc++.h> 
using namespace std;

int main() {
	int64_t n, k;
	cin >> n >> k;
	vector<int64_t> v(n);
	int64_t sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}
	int64_t val = 0;
	for (int bit = 40; bit >= 0; --bit) {
		int set = 0;
		for (int i = 0; i < n; ++i) {
			if ((v[i] >> bit) & 1) {
				set++;
			}
		}
		if ((n - set) > set && ((1LL << bit) + val) <= k) {
			val = (val | (1LL << bit));
		}
	}
	int64_t ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (val ^ v[i]);
	}
	cout << ans;
}
