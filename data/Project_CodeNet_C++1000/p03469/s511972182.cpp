#include <stdio.h>


int main (){
	char tanggal[11];
	scanf("%[^\n]", tanggal);
	
	tanggal[4]= '/';
	tanggal[7]='/';
	tanggal[3] += 1;
	printf("%s", tanggal);
	
	return 0;
}