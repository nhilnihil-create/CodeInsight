#include "bits/stdc++.h"
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int nmax = max(A, max(B, C));
	int ans = 3 * nmax - A - B - C;
	if (1 == ans % 2) {
		ans += 3;
	}
	ans /= 2;
	cout << ans << endl;
	return 0;
}
