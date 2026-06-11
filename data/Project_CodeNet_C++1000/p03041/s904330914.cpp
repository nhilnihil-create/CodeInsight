#include <stdio.h>

int main() {
	int A;
	int B;
	char s[55];
	
	scanf("%d %d", &A, &B);
	scanf("%s", s);
	
	s[B-1] += 32;
	
	printf("%s", s);
	
	
	return 0;
}