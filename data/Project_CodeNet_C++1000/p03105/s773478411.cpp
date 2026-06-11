#include<stdio.h>

int main(){
	
	int A,B,C;
	scanf("%d %d %d",&A,&B,&C);
	B=B+A;
	int x=0;
	
	do{
		B=B-A;
		if(x == C){
			break;
		}
		if(B < A){
			break;
		}
		x++;
	}while(B/A!=0);
	
	printf("%d\n",x);
	return 0;
}