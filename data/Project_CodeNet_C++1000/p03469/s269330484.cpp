#include <stdio.h>

int main(){
	
	char d[15] = "yyy/01/30";
	scanf("%s", &d);
	
	d[0] = '2';
	d[1] = '0';
	d[2] = '1';
	d[3] = '8';
	
	printf("%s", d);
	
	return 0;
}