#include <bits/stdc++.h>
using namespace std;
int n, a[55], b[55];
int solve() {
	sort(b+1, b+1+n);
	int ans = 0x3f3f3f3f;
	for (int i = 2; i <= n; i++) ans = min(ans, b[i]-b[i-1]);
	ans = min(ans, b[1]);
	ans = min(ans, 24-b[n]);
	return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	for (int i = 1; i <= n; i++) {
		if (i&1) b[i] = 24-a[i];
		else b[i] = a[i];
	}
	int ans = solve();
		for (int i = 1; i <= n; i++) {
		if (i&1) b[i] = a[i];
		else b[i] = 24-a[i];
	}
	ans = max(ans, solve());
	cout << ans << endl;
} 