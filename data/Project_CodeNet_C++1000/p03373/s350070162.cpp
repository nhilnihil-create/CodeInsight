#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans = 1e9;
	for (int i = 0; i <= 100000; i++) {
		ans = min((2*c*i + max(x-i, 0)*a + max(y-i, 0)*b), ans);

	}
	cout << ans << endl;

	return 0;
}
