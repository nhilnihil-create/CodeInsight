#include <stdio.h>

int main() {
	char word[53];
	int lgth, num;
	scanf("%d %d\n", &lgth, &num);
	scanf("%s", word);
	
	num--;
	word[num] += 32;
	printf("%s", word);
	
	return 0;
}