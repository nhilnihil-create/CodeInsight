#include <stdio.h>

int main() {
	int input1;
	int input2;
	char input3[102];
	
	scanf("%d %d", &input1, &input2);
	scanf("%s", input3);
	
	input3[input2-1] = input3[input2-1] + 32;
	
	printf("%s", input3);
	
	return 0;
}