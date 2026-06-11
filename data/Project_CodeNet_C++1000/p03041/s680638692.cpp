#include<stdio.h>
#include<string.h>
int main (){
	
	char strS[52];
	int smpe;
	int mana;
	
	1<=smpe<=50;
	1<=mana<=smpe;
	scanf("%d %d", &smpe, &mana);
	
	scanf("%s", &strS);
	mana = mana -1;
	strS [mana] +=32 ;
	printf("%s", strS);
	
	
	return 0;
}