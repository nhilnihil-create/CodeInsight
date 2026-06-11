#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> x(n), y(n);
	rep(i, n) {
		cin >> x[i] >> y[i];
	}
	vector<int> recx = x, recy = y;
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	ll ans = 1e20;
	for (int x1 = 0; x1 < n; ++x1) {
		for (int x2 = x1 + 1; x2 < n; ++x2) {
			for (int y1 = 0; y1 < n; ++y1) {
				for (int y2 = y1 + 1; y2 < n; ++y2) {
					int cnt = 0;
					rep(i, n) {
						if (recx[i] >= x[x1] && recx[i] <= x[x2] && recy[i] >= y[y1] && recy[i] <= y[y2]) cnt++;
					}
					if (cnt >= k) {
						mins(ans, ll(x[x2] - x[x1])* ll(y[y2] - y[y1]));
					}
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
