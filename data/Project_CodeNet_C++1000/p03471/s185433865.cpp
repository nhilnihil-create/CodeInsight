#include<iostream>
using namespace std;

int main() {

	int N, Y;
	bool ans = false;
	cin >> N >> Y;

	int x, y, z;

	for (x = 0; x <= N; x++) {
		for (y = 0; y <= N - x; y++) {
			z = N - x - y;
			if (10000 * x + 5000 * y + 1000 * z == Y) {
				ans = true;
				break;
			}
		}
		if (ans == true) break;
	}

	if (ans == true) cout << x << " " << y << " " << z;
	else cout << "-1 -1 -1";
	return 0;
}