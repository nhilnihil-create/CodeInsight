#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

signed main(void)
{
	int x, y, z, w, k;
	cin >> x >> y >> z >> k;
	vector<ll> a(x), b(y), c(z), d, e;
	rep(i, x) cin >> a[i];
	rep(i, y) cin >> b[i];
	rep(i, z) cin >> c[i];
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	rep(i, x) rep(j, y)
		d.push_back(a[i] + b[j]);
	sort(d.rbegin(), d.rend());
	w = d.size();
	w = min(w, 3000);
	rep(i, w) rep(j, z)
		e.push_back(d[i] + c[j]);
	sort(e.rbegin(), e.rend());
	rep(i, k) cout << e[i] << endl;
	return 0;
}
