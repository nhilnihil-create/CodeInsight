#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, nz; cin >> n;
	vector<int> x(n), y(n), h(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i] >> h[i];
		if (h[i] != 0) nz = i;
	}

	for (int cx = 0; cx <= 100; ++cx) {
		for (int cy = 0; cy <= 100; ++cy) {
			int H = h[nz] + abs(x[nz] - cx) + abs(y[nz] - cy);
			bool ok = true;
			for (int i = 0; i < n; ++i) {
				if (i == nz) continue;
				if (max(0, H - abs(x[i] - cx) - abs(y[i] - cy)) != h[i]) ok = false;
			}
			if (ok) {
				cout << cx << " " << cy << " " << H;
				return 0;
			}
		}
	}
	return 0;
}