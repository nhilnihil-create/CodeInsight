#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
	ll n, k; cin >> n >> k;
	vector<ll> x(n), y(n), xx, yy;
	rep(i, n) cin >> x[i] >> y[i];
	xx = x; yy = y;
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	ll ans = 1LL * (x[n - 1] - x[0])*(y[n - 1] - y[0]);
	rep(a, n) {
		for (int b = a + 1; b < n; b++) {
			rep(c, n) {
				for (int d = c + 1; d < n; d++) {
					int cnt = 0;
					rep(i, n) {
						if (x[a] <= xx[i] && xx[i] <= x[b] && y[c] <= yy[i] && yy[i] <= y[d])
							cnt++;
					}if (cnt >= k)ans = min(ans, 1LL * (x[b] - x[a])*(y[d] - y[c]));
				}
			}
		}
	}cout << ans << endl;
}