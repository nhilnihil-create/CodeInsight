#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int A, B;
	scanf("%d %d", &A, &B);
	printf("%d\n", max(A + B, max(A - B, A * B)));
	return 0;
}
