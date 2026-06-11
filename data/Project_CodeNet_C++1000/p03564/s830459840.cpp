#include <stdio.h>

int main (){
	int N,K,x=1;
	
	scanf ("%d",&N);
	scanf ("%d",&K);

	for (int i=0; i<N; i++){

		if (x*2 > x+K){
		x =	x + K;
		
		}
		else {
		x =	x * 2; 
		
		}	
	}
	printf ("%d",x);
	
	return 0;
}