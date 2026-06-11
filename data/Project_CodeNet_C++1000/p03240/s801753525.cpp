#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

const int N = 105;

int n;

int x[N], y[N], h[N];

int main() {

	FAST;

	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> x[i] >> y[i] >> h[i];
	}
	for (int cx = 0; cx <= 100; cx ++) {
		for (int cy = 0; cy <= 100; cy ++) {
			int H;
			for (int i = 1; i <= n; i ++) {
				if (h[i] > 0) {
					int k = abs(cx - x[i]) + abs(cy - y[i]);
					H = h[i] + k;
					break;	
				}
			}
			bool flag = true;
			for (int i = 1; i <= n; i ++) {
				int k = abs(cx - x[i]) + abs(cy - y[i]);
				if (h[i] != max(H - k, 0)) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << cx << ' ' << cy << ' ' << H << '\n';
				return 0;
			}
		}
	}
	return 0;
}