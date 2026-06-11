#include <stdio.h>

int main(){
	int panjangkata,kecilin;
	scanf("%d %d", &panjangkata,&kecilin);
	char huruf[panjangkata+5];
	scanf("%s",huruf);
	huruf[kecilin-1] += 32;
	printf("%s",huruf);
	
    return 0;
}