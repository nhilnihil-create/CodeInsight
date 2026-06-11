#include <stdio.h>

int main (){
	
	int kata, lowercase;
	
	scanf ("%d %d",&kata, &lowercase);
	char  huruf [kata+5]; 
	scanf("%s",huruf); 
 	huruf [lowercase-1]+=32;
 	printf ("%s",huruf);
 	
	return 0;
}
