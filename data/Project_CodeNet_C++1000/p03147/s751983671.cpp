#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> h(N);
	for (int i = 0; i < N; i++) cin >> h[i];

	int count = 0;

	for (int l = 0; l < N; l++) {
		int r;
		while (h[l] != 0) {
			int Min = h[l];
			for (r = 1; l + r < N; r++) {
				if (h[l + r] == 0) break;
				Min = min(Min, h[l + r]);
			}
			for (int i = l; i < l + r; i++) {
				h[i] -= Min;
			}
			count += Min;
		}
	}

	cout << count << endl;

	return 0;
}
