#include <stdio.h>

int main(){
	
	int lenght;
	int index;
	char character [55];
	scanf("%d %d", &lenght, &index);
	getchar();
	scanf("%s", &character);
	character [index-1] += 32;
	printf("%s\n", character);
		
	return 0;
}