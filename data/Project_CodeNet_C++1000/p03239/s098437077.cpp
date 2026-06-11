#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
	
	int n, T; cin >> n >> T;
	bool ok = false;
	int ans = 100000000;
	for (int i = 0; i < n; i++) {
		int c, t; cin >> c >> t;
		if (T < t) continue;
		if (chmin(ans, c)) {
			ok = true;
		}
	}
	if (ok) cout << ans << endl;
	else cout << "TLE" << endl;
	return 0;
}