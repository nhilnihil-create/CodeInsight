#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	
	int A[2][n];
	for (int row = 0; row < 2; ++row) {
		for (int col = 0; col < n; ++col) {
			int a; scanf("%d", &a);

			if (row > 0 && col > 0) a += max(A[row - 1][col], A[row][col - 1]);
			else if (row > 0) a += A[row - 1][col];
			else if (col > 0) a += A[row][col - 1];

			A[row][col] = a;
		}
	}
	
	printf("%d\n", A[1][n - 1]);
	return 0;
}