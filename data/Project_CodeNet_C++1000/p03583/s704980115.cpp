#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void) {
	ll N, h, n, bb, bs;

	cin >> N;

	for (h = 1; h <= 3500; h++) {
		for (n = h; n <= 3500; n++) {
			bs = N * h * n;
			bb = 4 * h * n - (h + n) * N;
			if (bb <= 0) continue;
			if (bs % bb == 0) {
				printf("%lld %lld %lld\n", h, n, bs / bb);
				return 0;
			}
		}
	}

	return 0;
}