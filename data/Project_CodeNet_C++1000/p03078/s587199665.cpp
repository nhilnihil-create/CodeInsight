#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b);
#define chmin(a, b) a = min(a, b);
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int x, y, z, k;
	cin >> x >> y >> z >> k;
	vector<ll> a(x), b(y), c(z);
	rep(i, x) cin >> a[i];
	rep(i, y) cin >> b[i];
	rep(i, z) cin >> c[i];
	sort(rall(a));
	sort(rall(b));
	sort(rall(c));
	ll l = 0, r = 30000000010LL;
	int cnt_r = 0;
	while(r - l > 1) {
		ll m = (l + r) / 2;
		int cnt = 0; // count of comb s.t. ai+bj+c?>=m
		rep(i, x) rep(j, y) {
			int l = -1, r = z;
			while(r - l > 1) {
				int m2 = (l + r) / 2;
				(a[i]+b[j]+c[m2] >= m ? l : r) = m2;
			}
			cnt += r;
		}
		if (cnt >= k) {
		       l = m;
		} else {
			r = m;
			cnt_r = cnt;
		}
	}
	vector<ll> ans(k - cnt_r, l);
	rep(i, x) rep(j, y) rep(p, z) {
		if (a[i] + b[j] + c[p] <= l) break;
		ans.push_back(a[i]+b[j]+c[p]);
	}
	sort(rall(ans));
	rep(i, k) cout << ans[i] << endl;
}
