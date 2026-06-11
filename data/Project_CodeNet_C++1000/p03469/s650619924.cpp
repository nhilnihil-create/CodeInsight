#include <stdio.h>
#include <string.h>

int main(){
	int a, b, c;



	scanf("%d/%d/%d", &a , &b ,&c);

	printf("%d/%02d/%02d", a + 1, b, c);
	return 0;
}