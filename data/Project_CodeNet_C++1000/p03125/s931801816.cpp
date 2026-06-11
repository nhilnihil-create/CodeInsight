#include <stdio.h>

int main() {
	int Zx, Xz;
	scanf("%d %d", &Zx, &Xz);
	if (Xz % Zx == 0) {
		printf("%d", Xz + Zx);
		return 0;
		}
		else {
			printf("%d", Xz - Zx);
		}
	return 0;
}