#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) if (s[i] != 'x') cnt++;
	if (cnt == 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0, j = 0; i < s.length(); i++) {
		if (s[i] != 'x') j++;
		if (j == (cnt + 1) / 2) {
			vector<pair<int, char>> L, R;
			int cur = 0;
			for (int k = 0; k <= i - (cnt & 1); k++) {
				if (s[k] != 'x') {
					L.emplace_back(cur, s[k]);
					cur = 0;
				} else cur++;
			}
			int tmp = 0;
			for (int k = s.length() - 1; k >= i + 1; k--) {
				if (s[k] != 'x') {
					R.emplace_back(tmp, s[k]);
					tmp = 0;
				} else tmp++;
			}
			if (L.size() != R.size()) {
				cout << -1 << endl;
				return 0;
			}
			for (int i = 0; i < L.size(); i++) if (L[i].second != R[i].second) {
				cout << -1 << endl;
				return 0;
			}
			int ans;
			if (cnt & 1) {
				ans = abs(cur - tmp);
			} else {
				ans = 0;
			}
			for (int i = 0; i < L.size(); i++) ans += abs(L[i].first - R[i].first);
			cout << ans << endl;
			return 0;
		}
	}
	return 0;
}

