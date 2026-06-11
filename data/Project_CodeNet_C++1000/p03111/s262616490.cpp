#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)

int main() {
	int n, a, b, c; cin >> n >> a >> b >> c;
	int l[8]; rep(i, 0, n) cin >> l[i];

	int ans = 10000;
	rep(i, 0, pow(4, n)) {
		int four = i;
		int alen = 0, blen = 0, clen = 0;
		int cost = 0;
		rep(j, 0, n) {
			int k = four % 4;
			if (k == 0) {
				cost += 10 * (alen != 0);
				alen += l[j];
			}
			if (k == 1) {
				cost += 10 * (blen != 0);
				blen += l[j];
			}
			if (k == 2) {
				cost += 10 * (clen != 0);
				clen += l[j];
			}
			four /= 4;
		}
		if (alen != 0 && blen != 0 && clen != 0) 
			ans = min(ans, cost + abs(a - alen) + abs(b - blen) + abs(c - clen));
	}
	cout << ans;
	return 0;
}
