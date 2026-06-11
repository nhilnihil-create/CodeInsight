#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
int Q, A, B;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> A >> B;
		if (A > B) swap(A, B);
		int l = 0, r = 2000000018;
		while (r - l > 1) {
			int m = ((long long)l + r) >> 1;
			int b = m / 2 + 1;
			long long val = (m & 1 ? 1LL * b * b : 1LL * b * (b - 1));
			if (m >= A * 2 - 2) val = (m & 1 ? 1LL * (b + 1) * b : (m == A * 2 - 2 || m == B * 2 - 2 ? 1LL * (b + 1) * (b - 1) : 1LL * b * b));
			if (m >= B * 2 - 1) val = (m & 1 ? 1LL * (b + 1) * (b + 1) : 1LL * (b + 1) * b);
			if (val >= 1LL * A * B) r = m;
			else l = m;
		}
		cout << l << "\n";
	}
	return 0;
}