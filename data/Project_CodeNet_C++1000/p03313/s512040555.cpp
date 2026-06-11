#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long li;
typedef pair<li, li> pii;

pii make_set(li x, li y) {
	if (x < y) {
		return make_pair(y, x);
	} else {
		return make_pair(x, y);
	}
}

pii max_of(pii x, pii y) {
	vector<li> vs = {x.first, x.second, y.first, y.second};
	sort(vs.begin(), vs.end());
	return make_set(vs[2], vs[3]);
}

int main() {
	li n;
	cin >> n;
	
	li m = 1 << n;
	
	vector<li> xs(m);
	for (int i = 0; i < m; ++i) {
		cin >> xs[i];
	}
	
	vector<vector<pair<li, li>>> dp(m, vector<pair<li, li>>(n + 1));
	
	for	(int mask = 0; mask < m; ++mask) {
		dp[mask][0] = make_pair(xs[mask], 0);
		for	(int p = 0; p < n; ++p) {
			dp[mask][p + 1] = dp[mask][p];
			if (mask & (1 << p)) {
				dp[mask][p + 1] = max_of(dp[mask][p + 1], dp[mask ^ (1 << p)][p]);
			}
		}
	}
	
	li ans = 0;
	for (int i = 1; i < m; ++i) {
		ans = max(ans, dp[i][n].first + dp[i][n].second);
		cout << ans << endl;
	}
	return 0;
}