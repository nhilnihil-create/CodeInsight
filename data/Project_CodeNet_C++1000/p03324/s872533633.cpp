#include<stdio.h>

int main(){
	
	int D, N;
	
	scanf("%d %d", &D, &N);
	
	int pengali = 1;
	for(int i = 0; i<D; i++){
		pengali *= 100;
	}
	if(N < 100){
		printf("%d", pengali * N);
	}
	else{
		printf("%d\n", pengali * 101);
	}
	return 0;
}