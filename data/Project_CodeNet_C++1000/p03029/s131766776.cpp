#include <stdio.h>

int main() {
	int apple;
	int pieces1;
	
	scanf("%d %d", &apple, &pieces1);
	printf("%d", ((apple*3) + pieces1) / 2);
	
	return 0;
}
