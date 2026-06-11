#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl

using namespace std;

const int MN = 200010;

long long a[MN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
		a[i] += a[i - 1];
	long long ans = 1e18;
	for (int i = 1; i + 2 < n; i++) {
		int p1 = lower_bound(a, a + n, a[i] / 2) - a;
		int p2 = lower_bound(a, a + n, (a[n - 1] + a[i]) / 2) - a;
		if (p1 - 1 >= 0 && abs(a[i] - 2 * a[p1 - 1]) < abs(a[i] - 2 * a[p1])) p1--;
		if (p2 - 1 > i && abs((a[n - 1] - a[i]) - 2 * (a[p2 - 1] - a[i])) < abs((a[n - 1] - a[i]) - 2 * (a[p2] - a[i]))) p2--;
		long long l1 = a[p1], l2 = a[i] - a[p1];
        long long r1 = a[p2] - a[i], r2 = a[n - 1] - a[p2];
        long long mx = max(max(l1, l2), max(r1, r2));
        long long mn = min(min(l1, l2), min(r1, r2));
        // cout << l1 << " " << l2 << " " << r1 << " " << r2 << endl;
        ans = min(ans, mx - mn);
	}
	cout << ans << endl;
	return 0;
}
