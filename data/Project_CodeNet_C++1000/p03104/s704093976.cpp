#include <vector>
#include <iostream>
using namespace std;
long long calc(long long a, long long b, long long l, long long r) {
	if (a <= l && r <= b) {
		if (r - l >= 4) return 0;
		long long res = 0;
		for (long long i = l; i < r; ++i) {
			res ^= i;
		}
		return res;
	}
	if (r <= a || b <= l) return 0;
	long long lc = calc(a, b, l, (l + r) >> 1);
	long long rc = calc(a, b, (l + r) >> 1, r);
	return lc ^ rc;
}
int main() {
	long long A, B;
	cin >> A >> B;
	long long res = calc(A, B + 1, 0, 1LL << 60);
	cout << res << endl;
	return 0;
}