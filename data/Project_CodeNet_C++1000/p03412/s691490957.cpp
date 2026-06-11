#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int a[N], b[N];
int fa[N], fb[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	int res = 0;
	for (int it = 0; it <= 28; ++it) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			fa[i] = a[i] & ((1 << (it + 1)) - 1);
			fb[i] = b[i] & ((1 << (it + 1)) - 1);
		}
		sort(fb + 1, fb + n + 1);
		for (int i = 1; i <= n; ++i) {
			cnt += lower_bound(fb + 1, fb + n + 1, 2 * (1 << it) - fa[i]) - lower_bound(fb + 1, fb + n + 1, (1 << it) - fa[i]);
			cnt += lower_bound(fb + 1, fb + n + 1, 4 * (1 << it) - fa[i]) - lower_bound(fb + 1, fb + n + 1, 3 * (1 << it) - fa[i]);
			cnt &= 1;
		}
		if (cnt) res += (1 << it);
	}
	cout << res << '\n';
}