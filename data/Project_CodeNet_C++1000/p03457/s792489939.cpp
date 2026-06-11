#include <cstdio>
#include <iostream>
#include <cmath>

int main(int argc, char const* argv[]) {
	int N;
	int t[100010], x[100010], y[100010];
	scanf("%d", &N);
	t[0] = 0;
	x[0] = y[0] = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &t[i], &x[i], &y[i]);
	}
	bool ans = true;
	for (int i = 1; i <= N; i++) {
		int difft = abs(t[i] - t[i - 1]);
		int diffx = abs(x[i] - x[i - 1]);
		int diffy = abs(y[i] - y[i - 1]);
		if (diffx + diffy > difft) {
			ans = false;
		}
		if ((diffx + diffy + difft) % 2 != 0) {
			ans = false;
		}
	}

	printf(ans ? "Yes" : "No");

	return 0;
}
