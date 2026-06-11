#include<stdio.h>

int main(){
	
	int panjangkata, lowercase;
	scanf("%d %d", &panjangkata, &lowercase);
	char kata[panjangkata + 3];
	scanf("%s", &kata);
	kata[lowercase - 1] += 32;
	printf("%s", kata);

	
	return 0;
}