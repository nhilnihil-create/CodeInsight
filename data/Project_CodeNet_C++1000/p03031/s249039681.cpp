#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> sw(n);
	rep(i, m) {
		int k;
		cin >> k;
		rep(j, k) {
			int s;
			cin >> s;
			sw[s - 1].push_back(i);
		}
	}
	vector<int> p(m);
	rep(i, m) cin >> p[i];
	int ans = 0;
	rep(bit, 1 << n) {
		vector<int> cnt(m);
		rep(i, n) {
			if (bit & (1 << i)) {
				for (auto a : sw[i]) cnt[a]++;
			}
		}
		bool ok = true;
		rep(i, m) if (cnt[i] % 2 != p[i]) ok = false;
		if (ok) ans++;
	}
	cout << ans << endl;
	return 0;
}