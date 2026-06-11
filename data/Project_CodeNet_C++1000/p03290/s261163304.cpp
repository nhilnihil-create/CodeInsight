#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 1e9;
int main() {
	int d, g;
	cin >> d >> g;
	vector<int> p(d), c(d);
	rep(i,d) cin >> p[i] >> c[i];
	int ans = INF;
	for (int bit = 0; bit < (1 << d); bit++) {
		int t = 0;
		int cnt = 0;
		for (int i = 0; i < d; i++) {
			if (bit & (1 << i)) {
				t += p[i] * (i+1) * 100 + c[i];
				cnt += p[i];
			}
		}
		for (int i = d-1; i >= 0; i--) {
			if (bit & (1 << i)) continue;
			for (int j = 1; j < p[i]; j++) {
				if (t >= g) break;
				t += (i+1) * 100;
				cnt++;
			}
			break;
		}
		if (t >= g) ans = min(ans, cnt);
	}
	cout << ans << endl;
}