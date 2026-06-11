#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	int A,B;
	scanf("%d %d",&A,&B);
	if(B%A==0) printf("%d\n",A+B);
	else printf("%d\n",abs(A-B));
	
	return 0;
}