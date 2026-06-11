#include <stdio.h>

int main(){
	int yy, mm, dd;
	
	scanf("%d/%d/%d", &yy, &mm, &dd);
	int yyup = yy + 1;
	
	printf("%d/%.2d/%.2d", yyup, mm, dd);
	
	return 0;
}