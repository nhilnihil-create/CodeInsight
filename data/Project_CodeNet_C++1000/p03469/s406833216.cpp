#include <stdio.h>
#include <string.h>

int main(){
	char S[120];
	scanf("%s", &S);
	getchar();
	
	S[0] = '2';
	S[1] = '0';	
	S[2] = '1';
	S[3] = '8';
	
	printf("%s", S);
	return 0;
}