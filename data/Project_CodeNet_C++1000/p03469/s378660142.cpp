#include<stdio.h>
int main(){
	char string[12]="";
	scanf("%s", &string);
	string[3]+=1;
	printf("%s\n",string);
	return 0;
}