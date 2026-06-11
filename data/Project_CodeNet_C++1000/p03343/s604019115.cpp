#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <random>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>


using namespace std;


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> b = a;
	sort(b.begin(), b.end());
	int ans = 1e9;
	for (int i = 0; i < b.size(); i++) {
		int l = -1, r = 1e9 + 2;
		while (r - l > 1) {
			int m = (l + r) / 2;
			int L = b[i];
			int R = b[i] + m;
			int col = 0;
			vector<int> sz = {0};
			vector<int> tt = {0};
			for (int i = 0; i < n; i++) {
				if (a[i] >= L) {
					sz[sz.size() - 1]++;
					if (a[i] <= R) {
						tt[tt.size() - 1]++;
					}
				}
				else {
					sz.push_back(0);
					tt.push_back(0);
				}
			}
			for (int i = 0; i < tt.size(); i++) {
				if (sz[i] >= k)
					col += min(sz[i] - k + 1, tt[i]);
			}
			if (col >= q)
				r = m;
			else
				l = m;
		}
		ans = min(ans, r);
	}
	cout << ans;
	return 0;
}
