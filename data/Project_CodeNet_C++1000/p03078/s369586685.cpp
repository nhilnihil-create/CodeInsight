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
const ll linf = (ll)4e18;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x, y, z, k;
	cin >> x >> y >> z >> k;
	vector<ll> a(x), b(y), c(z);
	rep(i, x) cin >> a[i];
	rep(i, y) cin >> b[i];
	rep(i, z) cin >> c[i];
	sort(all(a));
	sort(all(b));
	sort(all(c));
	vector<ll> sum;
	rep(i, x) {
		rep(j, y) {
			sum.push_back(a[i] + b[j]);
		}
	}
	sort(rall(sum));
	vector<ll> res;
	rep(i, z) {
		rep(j, min(k, (int)sum.size())) {
			res.push_back(c[i] + sum[j]);
		}
	}
	sort(rall(res));
	rep(i, k) cout << res[i] << endl;
	return 0;
}
