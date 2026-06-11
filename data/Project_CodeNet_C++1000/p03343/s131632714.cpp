#include<bits/stdc++.h>

#define int long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define TASK ""

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int N = 2005, INF = 1e9 + 7;

int n, k, q, a[N];

signed main() {
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
if (strlen(TASK) > 0)
	freopen(TASK".in", "r", stdin),
	freopen(TASK".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int ans = INF;
	for (int p = 1; p <= n; ++p) {
		int x = a[p];
		vector<pii> groups;
		int i = 1;
		while (i <= n) {
			if (a[i] < x) {
				++i;
				continue;
			}
			int j = i;
			while (j <= n && a[j] >= x) {
				++j;
			}
			--j;
			groups.pb(mp(i, j));
			i = j + 1;
		}
		vector<int> sex;
		for (int i = 0; i < sz(groups); ++i) {
			vector<int> curr;
			for (int j = groups[i].x; j <= groups[i].y; ++j) {
				curr.pb(a[j]);
			}
			sort(all(curr));
			for (int j = 0; j < sz(curr) - k + 1; ++j) {
				sex.pb(curr[j]);
			}
		}
		sort(all(sex));
		if (sz(sex) >= q) {
			ans = min(ans, sex[q - 1] - x);
		}
	}
	cout << ans << "\n";

	return 0;
}
