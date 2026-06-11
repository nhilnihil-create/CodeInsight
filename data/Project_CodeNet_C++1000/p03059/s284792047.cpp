#include<stdio.h>

int main(){
	int A,B,C;
	int Resul;
	scanf("%d %d %d",&A,&B,&C);
	
	for(int x = 1;A*x<=C;x++)
	{
		if(A*x<=C){
			Resul+=B;
		}
	}
	
	printf("%d\n",Resul);
	return 0;
}