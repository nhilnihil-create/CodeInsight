#include <cstdio>
#include <iostream>

int main(int argc, char const* argv[]) {
	int A, B, C, X;
	scanf("%d %d %d %d", &A, &B, &C, &X);
	int ans = 0;
	for (int i = 0; i < A + 1; i++) {
		if (500 * i > X) {
			continue;
		}
		for (int j = 0; j < B + 1; j++) {
			if (500 * i + 100 * j > X) {
				continue;
			}
			for (int k = 0; k < C + 1; k++) {
				if (500 * i + 100 * j + 50 * k == X) {
					ans++;
					break;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
