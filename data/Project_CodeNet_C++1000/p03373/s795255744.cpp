#include <iostream>
using namespace std;

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	if (A + B < 2 * C) cout << A * X + B * Y;
	else {
		int ans = 0;
		int min = X < Y ? X : Y;
		ans += 2 * C * min;
		X -= min;
		Y -= min;
		if (X > 0) ans += A < 2 * C ? A * X : 2 * C * X;
		if (Y > 0) ans += B < 2 * C ? B * Y : 2 * C * Y;
		cout << ans;
	}
}