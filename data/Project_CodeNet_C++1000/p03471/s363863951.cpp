#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
	int n; // nb
	int y; // yen
	cin >> n >> y;

	int a; // 10000
	int b; // 5000
	int c; // 1000

	for (a = 0; (10000 * a <= y) && (a <= n); a++) {
		for (b = 0; (10000 * a + 5000 * b <= y) && (a + b <= n); b++) {
			if (10000 * a + 5000 * b + 1000 * (n - a - b) == y) {
				cout << a << " " << b << " " << n - a - b;
				return 0;
			}
		}
	}

	cout << "-1 -1 -1" << endl;

	return 0;
}