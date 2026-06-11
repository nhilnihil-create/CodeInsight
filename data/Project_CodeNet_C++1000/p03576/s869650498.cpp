#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<ll, ll>> p(n);
	vector<ll> x(n), y(n);
	rep(i, n) {
		ll xt, yt;
		cin >> xt >> yt;
		p[i] = {xt, yt};
		x[i] = xt;
		y[i] = yt;
	}
	sort(all(x));
	sort(all(y));
	ll ans = 1LL << 62;
	for(int ix = 0; ix < n-1; ix++) {
		for(int jx = ix+1; jx < n; jx++) {
			for(int iy = 0; iy < n-1; iy++) {
				for(int jy = iy+1; jy < n; jy++) {
					int cnt = 0;
					rep(k, n) {
						ll kx = p[k].first;
						ll ky = p[k].second;
						if(kx >= x[ix] && kx <= x[jx]) {
							if(ky >= y[iy] && ky <= y[jy]) {
								cnt++;
							}
						}
					}
					if(cnt >= k) {
						ll area = (x[jx] - x[ix]) * (y[jy] - y[iy]);
						ans = min(ans, area);
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}