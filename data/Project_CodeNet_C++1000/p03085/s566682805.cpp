#include<stdio.h>
int main (void){
	char b ;
	scanf("%c", &b);
  	if (b=='A'){
    	printf("T");
    }
	if (b=='T'){
    	printf("A");
    }
	if (b=='C'){
    	printf("G");
    }
	if (b=='G'){
    	printf("C");
    }
	return 0;
}