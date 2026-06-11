#include <bits/stdc++.h>
#define INF 1001001001
using namespace std;
int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<int> l(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	int ans = INF;
	for (int bit = 0; bit < (1 << (n << 1)); bit++) {
		int cost = 0;
		int ta = 0, tb = 0, tc = 0;
		int ca = 0, cb = 0, cc = 0;
		for (int i = 0; i < n; i++) {
			int e = (bit >> (i * 2) & 3);
			if (e == 1) {
				ta += l[i];
				ca++;
			} else if (e == 2) {
				tb += l[i];
				cb++;
			} else if (e == 3) {
				tc += l[i];
				cc++;
			}
		}
		if (ca == 0 || cb == 0 || cc == 0)
			continue;
		cost += abs(ta - a);
		cost += abs(tb - b);
		cost += abs(tc - c);
		cost += 10 * (ca - 1);
		cost += 10 * (cb - 1);
		cost += 10 * (cc - 1);
		ans = min(ans, cost);
	}
	cout << ans << endl;
	return 0;
}