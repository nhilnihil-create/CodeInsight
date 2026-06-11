#include <stdio.h>

int main (){
	int num1, num2;
	char in [100];
	
	scanf ("%d %d", &num1, &num2);
	scanf ("%s", in);
	
	in[num2-1]=in[num2-1]+32;
	
	printf ("%s", in);
	return 0;
}