#include <stdio.h>

int main() {
	
	char S[15];
	
	scanf("%s", S);
	
	S[3] = ++S[3];
	
	printf("%s", S);
	
	return 0;
}