#include <stdio.h>
#include <string.h>

int main() {
	int Zx, Xy, Yz = 0;
	char Xz[14];
	scanf("%d %d", &Zx, &Xy);
	scanf("%s", &Xz);
	int lng = strlen(Xz);
	for (int u = 0; u < lng; u++) {
		if (Xz[Zx] != '-') {
			printf("No");
			return 0;
		}
		if ('0' <= Xz[u] && Xz[u] <= '9') {
			Yz++;
		}
	}
	if (Yz != (Zx + Xy)) {
		printf("No");
		return 0;
	}
	printf("Yes\n");
	return 0;	
}