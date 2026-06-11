#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// ABC002-D, Expected 1405, 9:50, First AC
	/*int n, m; cin >> n >> m;
	vector<vector<int>> g(n);
	rep(i, m) {
		int x, y; cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int ans = 0;
	rep(i, 1 << n) {
		bool ok = true;
		rep(j, n) {
			if (i >> j & 1) {
				rep(k, n) {
					if (i >> k & 1 && j != k) {
						bool ok2 = false;
						rep(l, g[j].size()) {
							if (g[j][l] == k) ok2 = true;
						}
						if (!ok2) {
							ok = false; break;
						}
					}
				}
				if (!ok) break;
			}
		}
		int tmpCount = 0;
		rep(j, n) tmpCount += i >> j & 1;
		if (ok) ans = max(ans, tmpCount);
	}
	cout << ans << endl;
	*/

	// Square869120Contest #4 B, 19:08, First AC
	/*int n, k; cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll ans = llINF;
	rep(i, 1 << n) {
		int c = 0;
		rep(j, n) c += i >> j & 1;
		if (c != k) continue;
		ll tmpMax = -1;
		ll tmpAns = 0;
		rep(j, n) {
			if (i >> j & 1) {
				tmpAns += max(0ll, tmpMax - a[j] + 1);
				tmpMax = max(tmpMax + 1, a[j]);
			}
			else {
				tmpMax = max(tmpMax, a[j]);
			}
		}
		ans = min(ans, tmpAns);
	}
	cout << ans << endl;
	*/

	// ABC145-C, 297, 17:15, First AC
	/*int n; cin >> n;
	vector<P> p(n);
	rep(i, n) cin >> p[i].first >> p[i].second;
	sort(ALL(p));
	double ans = 0;
	int num = 0;
	do {
		num++;
		double dist = 0;
		rep(i, n) {
			if (i == 0) continue;
			dist += sqrt((p[i].first - p[i - 1].first) * (p[i].first - p[i - 1].first) + (p[i].second - p[i - 1].second) * (p[i].second - p[i - 1].second));
		}
		ans += dist;
	} while (next_permutation(p.begin(), p.end()));
	cout << setprecision(15) << ans / num << endl;
	*/

	// ABC077-C, 1096, 24:50, First AC(難しかったけど面白かった)
	int n; cin >> n;
	vector<int> a(n), b(n), c(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, n) cin >> c[i];
	sort(ALL(a));
	sort(ALL(b));
	sort(ALL(c));
	ll ans = 0;
	rep(i, n) {
		if (b[i] <= a[0]) continue;
		if (c[n - 1] <= b[i]) continue;
		
		int up, down;
		auto upitr = lower_bound(ALL(a), b[i]);
		if (upitr == a.begin()) continue;
		up = upitr - a.begin();

		auto downitr = upper_bound(ALL(c), b[i]);
		if (downitr == c.end()) continue;
		down = downitr - c.begin();
		
		/*
		int l, r, m, up, down;
		l = -1;
		r = n;
		while (l + 1 < r) {
			m = (l + r) / 2;
			if (a[m] < b[i]) l = m;
			else r = m;
		}
		up = l;

		l = -1;
		r = n;
		while (l + 1 < r) {
			m = (l + r) / 2;
			if (c[m] <= b[i]) l = m;
			else r = m;
		}
		down = r;
		*/

		ans += ll(up) * ll(n - down);
	}
	cout << ans << endl;
	return 0;
}