#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	ll n, m; cin >> n >> m;
	if (n < m) swap(n, m);  // m <= n
	ll ans = 0;
	if (2 < m) {
		ans = (n - 2) * (m - 2);
	}
	else if (m == 1 && n == 1) {
		ans = 1;
	}
	else if (m == 1 && 2 <= n) {
		ans = n - 2;
	}
	else {
		ans = 0;
	}
	cout << ans << endl;
    return 0;
}