#include <stdio.h>

int main() {
	int Zx, Xz, dup = 1;
	scanf("%d", &Zx);
	scanf("%d", &Xz);
	for (int o = 0; o < Zx; o++) {
		if (dup < Xz) {
			dup *= 2;
		} else {
			dup += Xz;
		}
	}
	printf("%d", dup);
	return 0;
}