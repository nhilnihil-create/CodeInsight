#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int N, M, X;
	scanf("%d %d %d", &N, &M, &X);
	int A[100];
	for (int i = 0; i < M; i++) {
		scanf("%d", &A[i]);
	}
	int right = 0, left = 0;
	for (int i = 0; i < M; i++) {
		if (A[i] > X) right++;
		else left++;
	}
	printf("%d\n", min(right, left));

	return 0;
}
