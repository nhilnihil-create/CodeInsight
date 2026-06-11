#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
using LL = long long;
using ULL = unsigned long long;

void solve() {
	int l; cin >> l;
	vector<pair<pair<int, int>, int>> ans;

	for(int i = 2; i < 20; i++) {
		ans.push_back({ {i, i + 1}, 0 });
		ans.push_back({ {i, i + 1}, 1 << (19 - i) });
	}

	int w = 0;
	while(l >= 262144) {
		ans.push_back({ {1, 2}, w });
		w += 262144;
		l -= 262144;
	}
	for (int i = 2; i <= 20; i++) {
		if (l >> (20 - i) & 1) {
			ans.push_back({ {1, i}, w });
			w += 1 << (20 - i);
		}
	}

	cout << 20 << " " << ans.size() << endl;
	rep(i, ans.size()) cout
		<< ans[i].first.first << " "
		<< ans[i].first.second << " "
		<< ans[i].second << endl;
}

int main() {

	solve();

	return 0;
}
