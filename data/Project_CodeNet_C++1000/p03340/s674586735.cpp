#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define x first
#define y second
using namespace std;
using ll  = long long;
#define int ll

const int N = 1e6 + 100;

int n, a[N];
vector<int> g[20];

signed main() {
#ifdef LC
    assert(freopen("input.txt", "r", stdin));
#endif
    ios::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 0;

	for (int i = n - 1; i >= 0; --i) {
		int mn = n;
		for (int j = 0; j < 20; ++j) {
			if ((a[i] >> j) & 1) {
				if (g[j].size() > 1) {
					g[j].erase(g[j].begin());
				}
				g[j].push_back(i);
			}
			if (g[j].size() == 2) {
				mn = min(mn, g[j][0]);
			}
		}
		ans += mn - i;
	}
	cout << ans << "\n";
    return 0;
}
