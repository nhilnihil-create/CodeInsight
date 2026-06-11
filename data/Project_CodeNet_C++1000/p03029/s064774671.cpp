#include <stdio.h>

int main() {
	int apple, piece, applePie;
	scanf("%d %d", &apple, &piece);
	
	applePie = ((apple*3)+piece)/2;
	printf("%d", applePie);
	
	return 0;
}