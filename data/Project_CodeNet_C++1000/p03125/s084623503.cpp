#include<iostream>
#include<stdio.h>
using namespace std;

int main(void) {
	int A, B;
	scanf("%d %d", &A, &B);
	printf("%d\n", B % A == 0 ? A + B : B - A);
	return 0;
}
