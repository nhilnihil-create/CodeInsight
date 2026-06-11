#include <stdio.h>
#include <string.h>

int main(){
	int X, Y;
	scanf("%d %d", &X, &Y);
	
	(Y%X==0)?(printf("%d", X+Y)):(printf("%d", Y-X));
	return 0;
}