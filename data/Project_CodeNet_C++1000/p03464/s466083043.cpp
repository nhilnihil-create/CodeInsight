#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef long long ll;
typedef pair<int, int> P;
constexpr auto INF = INT_MAX/2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int k;
	cin >> k;
	V<int> a(k);
	rep(i, k)cin >> a[k - 1 - i];

	ll mx = 2, mn = 2;
	bool ok = true;
	
	rep(i, k) {
		ll u = mx / a[i] * a[i];
		ll d = ((mn - 1) / a[i] + 1) * a[i];
		if (u < d) { ok = false;break; }
		mx = u + a[i] - 1;
		mn = d;
	}

	if (ok)cout << mn << " " << mx << endl;
	else cout << -1 << endl;

}