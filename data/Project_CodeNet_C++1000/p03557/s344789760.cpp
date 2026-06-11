#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> b[i];
	rep(i,n) cin >> c[i];
	sort(a.begin(), a.end());
	sort(c.begin(), c.end());
	ll ans = 0;
	rep(i,n) {
		ll A = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
		ll C = c.end()	- upper_bound(c.begin(),c.end(), b[i]);
		ans += A*C;
		
	}
	cout << ans << endl;
	return 0;
}