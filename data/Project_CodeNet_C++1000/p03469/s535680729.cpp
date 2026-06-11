#include <stdio.h>
#include <string.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int max(int a, int b);
int min(int a, int b);
int abs(int a);

int a, b, c;
int main() {
	scanf("%d/%d/%d", &a, &b, &c);
	printf("%d/%02d/%02d\n", 2018, b, c);
	return 0;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;	
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int min(int a, int b) {
	return (a < b) ? a : b;
}

int abs(int a) {
	return (a < 0) ? -a : a;
}
