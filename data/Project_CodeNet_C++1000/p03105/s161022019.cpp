#include<stdio.h>

int main(){
	
	
	int A, B, C;
	
	scanf("%d %d %d", &A, &B, &C);
	
	int counter = 0;
	
	for(int i = 0; i < C; i++){
		counter++;
		if(B - A < 0){
			counter--;
			break;
		}
		B -= A;
	}
	
	printf("%d\n", counter);
	
	return 0;
}