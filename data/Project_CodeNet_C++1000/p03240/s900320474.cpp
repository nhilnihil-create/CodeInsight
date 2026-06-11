#include <bits/stdc++.h>
using namespace std;

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	int N;
	scanf("%d", &N);

	int x, y, h;
	vector<int> x_zero, y_zero;
	vector<int> x_pos, y_pos, h_pos;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &x, &y, &h);
		if (h == 0) {
			x_zero.insert(x_zero.end(), x);
			y_zero.insert(y_zero.end(), y);
		} else {
			x_pos.insert(x_pos.end(), x);
			y_pos.insert(y_pos.end(), y);
			h_pos.insert(h_pos.end(), h);
		}
	}

	for (int Cx = 0; Cx <= 100; Cx++) {
		for (int Cy = 0; Cy <= 100; Cy++) {
			int h_est = abs(x_pos[0] - Cx) + abs(y_pos[0] - Cy) + h_pos[0];
			for (int i = 1; i < x_pos.size(); i++) {
				if (h_est !=
				    abs(x_pos[i] - Cx) + abs(y_pos[i] - Cy) + h_pos[i]) {
					goto next_loop;
				}
			}
			for (int i = 0; i < x_zero.size(); i++) {
				if (h_est > abs(x_zero[i] - Cx) + abs(y_zero[i] - Cy)) {
					goto next_loop;
				}
			}

			cout << Cx << " " << Cy << " " << h_est;
			return 0;
		next_loop:
			continue;
		}
	}
	cout << "Notfound";
	return 0;
}