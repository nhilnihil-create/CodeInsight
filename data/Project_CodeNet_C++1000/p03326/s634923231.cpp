#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<ll>> a(n, vector<ll>(3));
	rep(i, n)rep(j, 3) cin >> a[i][j];
	ll ans = -inf;
	rep(bit, (1 << 3)) {
		vector<ll> now(n);
		rep(i, n) {
			ll cnt = 0;
			rep(j, 3) {
				if (bit & (1 << j)) cnt += a[i][j];
				else cnt -= a[i][j];
			}
			now[i] = cnt;
		}
		sort(rall(now));
		ll tmp = 0;
		rep(i, m) tmp += now[i];
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}
