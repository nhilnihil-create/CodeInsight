#include<iostream>
using namespace std;

int main(void) {
	int A, B, C, D;
	scanf("%d%d%d%d", &A, &B, &C, &D);
	printf("%d\n", min(A, B) + min(C, D));

	return 0;
}
