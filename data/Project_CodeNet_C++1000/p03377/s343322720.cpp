#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int A, B, X;
	scanf("%d %d %d", &A, &B, &X);
	printf(A <= X && X <= A + B ? "YES\n" : "NO\n");

	return 0;
}
