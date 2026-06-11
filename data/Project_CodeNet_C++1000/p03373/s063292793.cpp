#include "bits/stdc++.h"
using namespace std;

int main() {
	int A, B, C, X, Y, ans = 1000000000;
	cin >> A >> B >> C >> X >> Y;
	for (int i = 0; i <= max(X, Y); i++) {
		int Z = 2 * C * i + A * max(0, X - i) + B * max(0, Y - i);
		ans = min(ans, Z);
	}
	cout << ans;
}
