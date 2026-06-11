#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {

	int n, t, a; cin >> n >> t >> a;
	double x = 100000000000;
	int ans;
	for (int i = 0; i < n; i++) {
		double h; cin >> h;
		double e;
		e = t - h * 0.006;
		double tmp = abs(e - a);
		if (chmin(x, tmp)) {
			ans = i + 1;
		}
	}
	cout << ans << endl;
	return 0;
}