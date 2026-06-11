#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int ans = x * a + y * b;
	for (int i = 2; i <= 2 * 1E+05; i += 2) {
		if (i * c + max(x - i / 2, 0) * a + max(y - i / 2, 0) * b < ans) {
			ans = i * c + max(x - i / 2, 0) * a + max(y - i / 2, 0) * b;
		}
	}

	cout << ans << endl;

 	return 0;
 }