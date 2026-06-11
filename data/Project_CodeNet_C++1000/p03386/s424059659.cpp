#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int A, B, K;
	scanf("%d %d %d", &A, &B, &K);
	for (int i = A; i < min(A + K, B + 1); i++) {
		printf("%d\n", i);
	}
	for (int i = max(A + K, B - K + 1); i <= B; i++) {
		printf("%d\n", i);
	}

	return 0;
}
