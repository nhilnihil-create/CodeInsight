#include <iostream>
using namespace std;
int n, x, y, a[100009];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (x < a[i]) x = a[i];
	}
	int e = x + 1;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) continue;
		if (2 * a[i] < x && e > x - 2 * a[i]) {
			y = a[i];
			e = x - 2 * a[i];
		}
		if (2 * a[i] >= x && e > 2 * a[i] - x) {
			y = a[i];
			e = 2 * a[i] - x;
		}
	}
	cout << x << ' ' << y << "\n";
	return 0;
}