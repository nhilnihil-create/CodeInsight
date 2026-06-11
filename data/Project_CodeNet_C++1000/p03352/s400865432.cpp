#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int X;
	cin >> X;

	int ans = 1;
	double sq = sqrt(X);

	for (int b = 1; b <= X; ++b) {
		int tmp = b;
		for (int p = 2; p <= 10; ++p) {
			tmp *= b;

			if (tmp <= X) {
				ans = max(ans, tmp);
			}
			else {
				break;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
