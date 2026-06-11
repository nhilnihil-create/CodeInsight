#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int D, G;
	cin >> D >> G;

	vector<int> p(D), c(D);
	for (int i = 0; i < D; i++) {
		cin >> p.at(i) >> c.at(i);
	}

	int ans = INT_MAX;
	for (int bit = 0; bit < (1 << D); bit++) {
		int sum = 0;
		int cnt = 0;
		vector<int> v;

		for (int i = 0; i < D; i++) {
			if (bit & (1 << i)) {
				sum += 100 * (i + 1) * p.at(i) + c.at(i);
				cnt += p.at(i);
			}
			else {
				v.push_back(i);
			}
		}

		if (sum < G) {
			for (int i = v.size() - 1; i >= 0; i--) {
				for (int j = 0; j < p.at(v.at(i)); j++) {
					sum += 100 * (v.at(i) + 1);
					cnt++;
					if (sum >= G) break;
				}
				if (sum >= G) break;
			}
		}

		ans = min(ans, cnt);
	}

	cout << ans << endl;
}