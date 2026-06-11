#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	ll ans = 0;
	ll sum = 0;
	vector<ll> d(n);
	rep(i, n) {
		d[i] = a[i] - b[i];
		if (d[i] < 0) {
			ans++;
			sum += -d[i];
		}
	}
	sort(d.rbegin(), d.rend());
	rep(i, n) {
		if (sum <= 0) break;
		if (d[i] > 0) {
			sum -= d[i];
			ans++;
		}
	}
	if (sum > 0) ans = -1;
	cout << ans << endl;
	return 0;
}