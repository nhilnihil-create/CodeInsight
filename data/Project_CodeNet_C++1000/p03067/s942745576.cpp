#include<stdio.h>

int main(){
	int A,B,C,D;
  	scanf("%d%d%d",&A,&B,&C);
  	if(A > B){
    	D = A;
      	A = B;
      	B = D;
    }
  	if(A < C && B > C){
    	printf("Yes\n");
    } else {
    	printf("No\n");
    }
}