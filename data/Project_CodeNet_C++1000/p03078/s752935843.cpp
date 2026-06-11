#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

int main() {

	int x, y, z, k;
	cin >> x >> y >> z >> k;
	V<ll> a(x), b(y), c(z);
	rep(i, x)cin >> a[i];
	rep(i, y)cin >> b[i];
	rep(i, z)cin >> c[i];
	sort(all(a));
	sort(all(b));
	sort(all(c));

	ll l = 2, r = 30000000001;
	while (r - l > 1) {
		
		ll m = (l + r) / 2;
		ll cnt = 0;
		rep(i, x)rep(j, y) {
			ll res = m - a[i] - b[j];
			cnt += c.end() - lower_bound(all(c), res);
		}
		if (cnt >= k)l = m;
		else r = m;
	}

	V<ll> ans;
	rep(i, x)rep(j, y) {
		ll res = l - a[i] - b[j];
		int cnt = c.end() - upper_bound(all(c), res);
		rep(s, cnt)ans.push_back(a[i] + b[j] + c[z - 1 - s]);
	}

	sort(all(ans), greater<ll>());
	for (auto x : ans)cout << x << endl;
	rep(j, k - ans.size())cout << l << endl;

}