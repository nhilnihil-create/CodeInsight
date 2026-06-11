#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	ll d, g; cin >> d >> g;
	vector<ll> p(d), c(d);	
	for (ll i = 0; i < d; i++) {
		cin >> p[i] >> c[i];
	}
	ll ans = 9223372036854775807LL;
	for (int bit = 0; bit < (1 << d); ++bit) {
		ll tmpAns = 0;
		ll tmpPointSum = 0;
		vector<bool> used(d, false);
		for (ll i = 0; i < d; ++i) {
			if (bit & (1 << i)) {
				used[i] = true;
				tmpAns += p[i];
				tmpPointSum += (i + 1) * 100 * p[i];
				tmpPointSum += c[i];
			}
		}
		if (g <= tmpPointSum) {
			ans = min(ans, tmpAns);
			continue;
		}
		for (ll i = d - 1; i >= 0; i--) {
			if (used[i]) continue;
			ll p_cnt = p[i] - 1;
			while (p_cnt--) {
				tmpPointSum += (i + 1) * 100;
				tmpAns++;
				if (g <= tmpPointSum) {
					ans = min(ans, tmpAns);
					break;
				}				
			}
			break;
		}
	}
	cout << ans << endl;
	return 0;
}