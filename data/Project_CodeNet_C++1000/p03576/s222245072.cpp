#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;


int main(void) {
	int n, k, i, j, l, x, y;
	ll ans = 1e20, s, h;
	vector<P> p;

	cin >> n >> k;
	for (i = 0; i < n; i++) {
		cin >> x >> y;
		p.push_back(P(x, y));
	}

	sort(p.begin(), p.end());

	for (i = 0; i < n; i++) for (j = i + k - 1; j < n; j++) {
		vector<ll> yp;
		for (l = i; l <= j; l++) {
			yp.push_back(p[l].second);
		}
		sort(yp.begin(), yp.end());
		h = 2e9;
		for (l = 0; l + k - 1 < j - i + 1; l++) {
			h = min(h, yp[l + k - 1] - yp[l]);
		}
		s = ((ll)p[j].first - p[i].first) * h;
		ans = min(ans, s);
	}

	cout << ans << endl;

	return 0;
}