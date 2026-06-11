#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
template<typename T> inline void chmax(T &a, T b){
	if(a < b) a = b;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<ll> x(n), y(n), z(n);
	rep(i, n) cin >> x[i] >> y[i] >> z[i];
	const int s[8][3] = {{1, 1, 1}, {1, 1, -1}, {1, -1, 1}, {1, -1, -1}, {-1, 1, 1}, {-1, 1, -1}, {-1, -1, 1}, {-1, -1, -1}};
	ll ans = 0;
	rep(k, 8) {
		vector<ll> tmp(n);
		rep(i, n) {
			tmp[i] = s[k][0] * x[i] + s[k][1] * y[i] + s[k][2] * z[i];
		}
		sort(all(tmp));
		reverse(all(tmp));
		ll now = 0;
		rep(i, m) now += tmp[i];
		ans = max(ans, now);
	}
	cout << ans << endl;
	return 0;
}