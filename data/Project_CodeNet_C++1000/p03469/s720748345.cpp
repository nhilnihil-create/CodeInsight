#include<stdio.h>
int main(){
	char date[12];
	scanf("%s", &date);
	date[3] = date[3]+1;
	printf("%s", date);
	return 0;
}