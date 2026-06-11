#include <stdio.h>

int main(){
	
	char y[4], m[2], d[2] = {0};
	
	scanf("%[^/]/%[^/]/%s", y, m, d);
	 
	 
	printf("2018/01/%s\n", d);
	return 0;
}