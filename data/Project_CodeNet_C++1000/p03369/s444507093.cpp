#include<stdio.h>
#include<string.h>

int main(void){
	char S[4];
	int counter=0;
	scanf("%3s",S);
	for(int i=0;i<strlen(S);i++){
		if(strncmp(&S[i],"o",sizeof(S[0]))==0) counter++;
		}
	int total=700+100*counter;
	printf("%d\n",total);
}