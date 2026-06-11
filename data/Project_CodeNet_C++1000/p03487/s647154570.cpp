#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
	int n;
	cin >> n;
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (cnt.count(a)) {
			cnt[a]++;
		} else {
			cnt.emplace(a, 1);
		}
	}
	int ans = 0;
	for (auto x : cnt) {
		int diff = x.second - x.first;
		ans += (diff < 0) ? x.second : diff;
	}
	cout << ans << endl;
}