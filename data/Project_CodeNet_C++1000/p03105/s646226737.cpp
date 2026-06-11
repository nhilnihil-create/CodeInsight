#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	if (B >= A * C ) {
		printf("%d\n", C);
	} else if (B < A * C && int (B / A) != 0) {
		printf("%d\n", int (B / A));
	} else {
		printf("0\n");
	}
	return 0;
}