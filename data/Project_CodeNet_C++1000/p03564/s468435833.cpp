#include<stdio.h>
int main(){
	int N;
	int K;
	int A = 1;
	scanf("%d", &N);
	scanf("%d", &K);
	for(int i = 0 ; i < N ; i++){
		if(A <= K){
			A *= 2;
		}else{
			A += K;
		}
	}
	printf("%d", A);
	return 0;
}