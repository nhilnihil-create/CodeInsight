#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n, m; cin >> n >> m;
	ll ans = 0;;
	int e = 1;
	int tmp_m = m;
	while (tmp_m--) {
		e *= 2;
	}
	ans += 1900 * m * e;
	ans += (n - m) * 100 * e;
	cout << ans << endl;
	return 0;
}