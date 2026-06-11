#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int d, g; cin >> d >> g;
	vector<int> p(d), c(d);
	for (int i = 0; i < d; i++) {
		cin >> p[i] >> c[i];
	}
	int ans = 2147483647;
	for (int bit = 0; bit < (1 << d); ++bit) {
		int tmpAns = 0;
		int tmpScore = 0;
		for (int i = 0; i < d; ++i) {
			if (bit & (1 << i)) {
				tmpAns += p[i];
				tmpScore += 100 * (i + 1) * p[i];
				tmpScore += c[i];
			}
		}
		if (g <= tmpScore) {
			ans = min(ans, tmpAns);
		}
		else {
			for (int i = d - 1; i >= 0; i--) {
				if (bit & (1 << i)) continue;
				for (int j = 0; j < p[i] - 1; j++) {
					tmpAns += 1;
					tmpScore += 100 * (i + 1);
					if (g <= tmpScore) {
						ans = min(ans, tmpAns);
						break;
					}
				}				
			}
		}
	}

	cout << ans << endl;
	return 0;
}