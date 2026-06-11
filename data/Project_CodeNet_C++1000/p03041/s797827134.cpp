#include <stdio.h>
int main(){
	int iN,iK;
	char cS[100];
	
	scanf("%d %d" , &iN,&iK);
	getchar();
	scanf("%[^\n]" , cS);
	cS[iK-1] += 32;
	printf("%s" , cS);
	
	return 0;
}