#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char const* argv[]) {
	int N;
	scanf("%d", &N);
	int A[2][100];
	int lowerSum = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
			if (i == 1) lowerSum += A[1][j];
		}
	}
	int ans = 0;
	int upperSum = 0;
	for (int i = 0; i < N; i++) {
		if (i > 0) lowerSum -= A[1][i - 1];
		upperSum += A[0][i];
		for (int j = 0; j < i + 1; j++) {
			ans = max(ans, upperSum + lowerSum);
		}
	}
	printf("%d", ans);
	return 0;
}
