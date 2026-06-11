#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int m, k;
	cin >> m >> k;
	int p = pow(2, m);
	if (k >= p) {
		cout << -1 << endl;
		return 0;
	}
	if (m == 1) {
		if (k == 0) {
			cout << "0 0 1 1" << endl;
			return 0;
		} else {
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = p-1; i >= 0; i--) {
		if (i != k) cout << i << ' ';
	}
	cout << k << ' ';
	for (int i = 0; i < p; i++) {
		if (i != k) cout << i << ' ';
	}
	cout << k << endl;
	return 0;
}