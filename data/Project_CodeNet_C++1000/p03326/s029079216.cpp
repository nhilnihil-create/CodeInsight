#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	long long x[N], y[N], z[N], array[N], max = 0, tmp = 0;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i] >> z[i];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < N; j++) {
			array[j] = (1 - 2 * (i / 4)) * x[j] + (1 - 2 * ((i / 2) % 2)) * y[j] + (1 - 2 * (i % 2)) * z[j];
		}
		sort(array, array + N);
		tmp = 0;
		for (int j = 0; j < M; j++) {
			tmp += array[N - 1 - j];
		}
		if (max < tmp) {
			max = tmp;
		}
	}
	cout << max << endl;

	return 0;
}