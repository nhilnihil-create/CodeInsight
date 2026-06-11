#include <stdio.h>

int main(){
	
	int a, ap;
	scanf("%d %d", &a, &ap);
	a = a * 3;
	
	int total = a + ap;
	
	printf("%d", total/2);
	
	
	return 0;
}