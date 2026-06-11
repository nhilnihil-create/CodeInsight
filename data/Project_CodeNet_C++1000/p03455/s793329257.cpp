#include <stdio.h>

int main(void){
  int a, b, c;

	scanf("%d", &a);
	scanf("%d", &b);

	c = (a*b)/2;
	
	if(a*b-c*2) printf("Odd\n");
	else printf("Even\n");
	return(0);
}

