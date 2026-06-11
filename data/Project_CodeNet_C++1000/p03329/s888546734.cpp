// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL n;
	cin >> n;
	LL ans = n;
	for (LL i = 0; i <= n; ++i) {
		LL c = 0;
		LL a;
		LL r = i;
		for (a = 6; a <= r; a *= 6) {
			;
		}
		a /= 6;
		while (a > 0) {
			LL d = r / a;
			r -= a * d;
			c += d;
			a /= 6;
		}
		r = n - i;
		for (a = 9; a <= r; a *= 9) {
			;
		}
		a /= 9;
		while (a > 0) {
			LL d = r / a;
			r -= a * d;
			c += d;
			a /= 9;
		}
		ans = min(ans, c);
	}
	cout << ans << endl;
	return 0;
}
