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
	ll n, h;
	cin >> n >> h;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	ll ans = 0;
	for (auto i : b) {
		if (i <= a[0]) break;
		h -= i;
		ans++;
		if (h <= 0) break;
	}
	if (h > 0) ans += (h + a[0] - 1) / a[0];
	cout << ans << endl;
	return 0;
}
