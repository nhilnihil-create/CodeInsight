#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int A, B, T;
	scanf("%d %d %d", &A, &B, &T);

	printf("%d\n", B * (T / A));
	return 0;
}
