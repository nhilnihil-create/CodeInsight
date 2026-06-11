#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t n; cin >> n;
	int64_t a, b; cin >> a >> b;
	if(a + b - 1 > n) {
		cout << -1 << '\n';
		return 0;
	}
	if(a * b < n) {
		cout << -1 << '\n';
		return 0;
	}
	vector<int> ans;
	ans.reserve(n);
	for(int i = b; i >= 1; --i) {
		ans.push_back(i);
	}
	int64_t res = n - b - (a - 1);
	int64_t now = b + 1;
	for(int i = 1; i < a; ++i) {
		int u = now + min<int64_t>(res, b - 1);
		for(int j = u; j >= now; --j) {
			ans.push_back(j);
		}
		now = u + 1;
		res -= min<int64_t>(res, b - 1);
	}
	for(int i = 0; i < n; ++i) {
		cout << ans[i] << (i == n - 1 ? "\n" : " ");
	}
	return 0;
}