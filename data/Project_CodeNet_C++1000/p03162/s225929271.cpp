#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int A[maxn], B[maxn], C[maxn];
int main(int argc, char const *argv[])
{
	int n; scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &A[i], &B[i], &C[i]);
	}

	for(int i = 1; i < n; i++){
		int tmpA = A[i-1], tmpB = B[i-1], tmpC = C[i-1];

		A[i] += max(tmpB, tmpC);
		B[i] += max(tmpA, tmpC);
		C[i] += max(tmpA, tmpB);
	}
	printf("%d\n", max(max(A[n-1], B[n-1]), C[n-1]));
	
	return 0;
}