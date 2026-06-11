#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N, A, B;
	scanf("%d %d %d", &N, &A, &B);
	printf("%d\n", min(A * N, B));
	return 0;
}
