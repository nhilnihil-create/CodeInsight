#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;
	vector<vector<int>> s(m);
	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int x; cin >> x;
			x--;
			s[i].push_back(x);
		}
	}
	vector<int> p(m);
	for (int i = 0; i < m; i++) {
		cin >> p[i];
	}
	int ans = 0;
	for (int bit = 0; bit < (1 << n); ++bit) {
		vector<bool> switchOn(n, false);
		for (int i = 0; i < n; ++i) {
			if (bit & (1 << i)) {
				switchOn[i] = true;
			}
		}		
		int onCnt = 0;
		for (int i = 0; i < m; i++) {
			int tmpCnt = 0;
			for (auto u : s[i]) {
				if (switchOn[u]) tmpCnt++;
			}
			if (tmpCnt % 2 == p[i]) onCnt++;
		}
		if (onCnt == m) ans++;
	}
	cout << ans << endl;
	return 0;
}