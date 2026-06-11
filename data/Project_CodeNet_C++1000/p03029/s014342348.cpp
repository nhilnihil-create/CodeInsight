#include <stdio.h>

	int main() {
		int piece;
		int apple;
		
		scanf("%i %i", &apple, &piece);
		
		int applepie;
		applepie = (apple*3 + piece)/2;
		
		printf("%i\n", applepie);
		
		return 0;
	}