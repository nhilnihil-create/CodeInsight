#include <stdio.h>
 
int main() {
	int N, K, A;
	char nama [52];

	scanf("%d %d %d", &N, &K, &A);
	scanf ("%s", &nama);
	A = K-1 ;
	nama [A] = nama [A] + 32 ;

	printf("%s", nama ) ;
	
	return 0;
}