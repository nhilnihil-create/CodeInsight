#include <stdio.h>

int main() {
	int number, character;
	scanf("%d %d", &number, &character);
	
	char string[number+1];
	scanf("%s", string);
	
	string[character-1] += 32;
	printf("%s\n", string);

	return 0;
}
