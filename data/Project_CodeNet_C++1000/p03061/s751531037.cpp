#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int a[N], l[N], r[N];
signed main(void) {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) l[i] = __gcd(l[i - 1], a[i]);
	for (int i = n; i >= 1; i--) r[i] = __gcd(r[i + 1], a[i]);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, __gcd(l[i - 1], r[i + 1]));
	}
	cout << ans << endl;
	return 0;
}