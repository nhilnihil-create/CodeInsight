#include <stdio.h>
 int main (){
	
	int apple; 
	scanf ("%d",&apple);
	int potongan;
	potongan = apple*3;
	int pieces;
	scanf ("%d", &pieces);
	int pie; 
	pie = (pieces+potongan) / 2;
	printf("%d ", pie);
	
return 0;
}