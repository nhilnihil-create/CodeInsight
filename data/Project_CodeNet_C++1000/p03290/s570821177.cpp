
// C - All Green

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int p[11];
int c[11];

int main() {
	int D, G;
	cin >> D >> G;

	for (int i=1; i<=D; i++) {
		cin >> p[i] >> c[i];
	}

	int ans = INF;

	for (int bits=0; bits < (1<<D); bits++) {
		int n_solve = 0;
		int score = 0;
		for (int i=1; i<=D; i++) {
			if (bits & (1<<(i-1))) {
				// 100i problems are completed.
				n_solve += p[i];
				score += i * 100 * p[i] + c[i];
			}
		}

		for (int i=D; i>=1; i--) {
			if (bits & (1<<(i-1))) continue;

			for (int j=0; j<p[i]; j++) {
				if (score >= G) break;

				n_solve++;
				score += 100 * i;
			}
		}

		ans = min(ans, n_solve);
	}

	cout << ans << endl;

	return 0;
}