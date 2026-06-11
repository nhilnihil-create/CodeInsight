#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	ll sum = 0;
	rep(i, n) sum += b[i];
	vector<ll> res(n);
	rep(i, n) res[i] = a[i] + b[i];
	sort(res.rbegin(), res.rend());
	ll ans = 0;
	rep(i, n) {
		if (i % 2 == 0)ans += res[i];
	}
	ans -= sum;
	cout << ans << endl;
	return 0;
}
