#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int L = 29;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& x : a) {
		cin >> x;
	}
	for (auto& x : b) {
		cin >> x;
	}
	ll ans = 0;
	for (int i = 0; i < L; i++) {
		int msk = (1 << i) - 1;
		vector<vector<int>> aa(2), bb(2);
		for (auto x : a) {
			aa[x >> i & 1].push_back(x & msk);
		}
		for (auto x : b) {
			bb[x >> i & 1].push_back(x & msk);
		}
		for (int j = 0; j < 2; j++) {
			sort(aa[j].begin(), aa[j].end());
			sort(bb[j].begin(), bb[j].end());
		}
		ll cur = 0;
		for (int j = 0; j < 2; j++) {
			for (int x : aa[j]) {
				// y >= 2^i - x
				cur += bb[j].size() - (lower_bound(bb[j].begin(), bb[j].end(), (1 << i) - x) - bb[j].begin());
			}
		}
		for (int j = 0; j < 2; j++) {
			for (int x : aa[j]) {
				// y < 2^i - x
				cur += lower_bound(bb[!j].begin(), bb[!j].end(), (1 << i) - x) - bb[!j].begin();
			}
		}
		if (cur & 1) {
			ans ^= (1 << i);
		}
	}
	cout << ans << endl;
}
