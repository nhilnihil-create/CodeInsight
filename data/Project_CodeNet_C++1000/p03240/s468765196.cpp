#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	long long n, xx = 0, yy = 0, hh = 0; cin >> n;
	long long x[105], y[105], h[105];
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> h[i];
		if (h[i] >= 1) { xx = x[i], yy = y[i], hh = h[i]; }
	}

	for (int xi = 0; xi <= 100; xi++) {
		for (int yi = 0; yi <= 100; yi++) {
			bool ok = true;
			long long hi = max(abs(xx - xi) + abs(yy - yi) + hh, 0LL);
			for (int i = 0; i < n; i++) {
				if (max(hi - abs(x[i] - xi) - abs(y[i] - yi),0LL) != h[i])ok = false;
			}
			if (ok) {
				cout << xi << ' ' << yi << ' ' << hi << endl;
			}
		}
	}

	return 0;
}