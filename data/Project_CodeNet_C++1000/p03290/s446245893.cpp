#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int D, G;
	cin >> D >> G;
	vector<int> p(D), c(D);
	for (int i = 0; i < D; i++) cin >> p[i] >> c[i];

	int score, count;
	int ans = 1500;

	for (int bit = 0; bit < (1 << D); bit++) {
		score = 0;
		count = 0;
		int j = -1;
		for (int i = 0; i < D; i++) {
			if (bit & (1 << i)) {
				score += 100 * (i + 1) * p[i] + c[i];
				count += p[i];
			}
			else j = max(j, i);
		}
		if (score >= G) ans = min(ans, count);
		else {
			for (int k = 0; k < p[j]; k++) {
				score += 100 * (j + 1);
				count++;
				if (score >= G) {
					ans = min(ans, count);
					break;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}