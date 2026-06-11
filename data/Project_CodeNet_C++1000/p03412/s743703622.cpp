#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const long long inf = 1ll<<61;
const long double pi = 3.1415926535897932384626433;
typedef pair<int, int> P;
typedef pair<int, P> PP;
struct edge { int to, cost; };

int a[200006], b[200006];

signed main() {
	int n; cin >> n;
	rep(i, n)cin >> a[i];
	rep(i, n)cin >> b[i];
	int ans = 0;

	rep(i, 30) {
		int bit = 0;
		int X = 1ll << (i + 1);
		vector<int>va, vb;
		rep(j, n) va.push_back(a[j] % X);
		rep(j, n)vb.push_back(b[j] % X);
		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end());
		rep(j, n) {
			if (i) {
				int si, sj, ti, tj;
				si = 1ll << i;
				sj = si * 2 - 1;
				ti = si * 3;
				tj = si * 4 - 1;
				si -= va[j];
				sj -= va[j];
				ti -= va[j];
				tj -= va[j];
				bit += upper_bound(vb.begin(), vb.end(), sj) - lower_bound(vb.begin(), vb.end(), si);
				bit += upper_bound(vb.begin(), vb.end(), tj) - lower_bound(vb.begin(), vb.end(), ti);
			}
			else {
				int si = 1;
				si -= va[j];
				bit += upper_bound(vb.begin(), vb.end(), si) - lower_bound(vb.begin(), vb.end(), si);
			}
		}
		if (bit & 1)ans += 1 << i;
	}
	cout << ans << endl;
}