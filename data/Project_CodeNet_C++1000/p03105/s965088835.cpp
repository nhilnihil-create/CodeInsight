#include<iostream>
#include<stdio.h>
using namespace std;

int main(void) {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf("%d\n", min(C, B / A));
	return 0;
}
