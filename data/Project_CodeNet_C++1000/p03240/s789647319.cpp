
// C - Pyramid

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int x[100], y[100], h[100];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> x[i] >> y[i] >> h[i];
	}

	int ans_cx, ans_cy, ans_h;
	for (int cx=0; cx<=100; cx++) {
		for (int cy=0; cy<=100; cy++) {
			bool valid = true;
			int tmp_H = INF;

			for (int i=0; i<N; i++) {
				if (h[i] != 0) tmp_H = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
			}

			for (int i=0; i<N; i++) {
				if (h[i] == 0) {
					if (tmp_H > h[i] + abs(x[i] - cx) + abs(y[i] - cy)) {
						valid = false;
						break;
					}
				} else {
					if (tmp_H != h[i] + abs(x[i] - cx) + abs(y[i] - cy)) {
						valid = false;
						break;
					}
				}
			}

			if (valid) {
				ans_cx = cx;
				ans_cy = cy;
				ans_h = tmp_H;
			}
		}
	}

	cout << ans_cx << " " << ans_cy << " " << ans_h << endl;

	return 0;
}