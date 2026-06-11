#include <stdio.h>

int main (){
	int y,m,d;
	
	scanf ("%d/%d/%d", &y,&m,&d);
	y=2018;
	printf ("%d/%02d/%02d",y,m,d);
	
	return 0;
}