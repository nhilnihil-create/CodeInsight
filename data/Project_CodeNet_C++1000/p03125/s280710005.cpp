#include<stdio.h>
int main(){
	int A;
	int B;
	int result;
	scanf("%d %d", &A, &B);
	if(B%A ==0){
		printf("%d", A + B);
	}else{
		printf("%d", B-A);
	}
	return 0;
}