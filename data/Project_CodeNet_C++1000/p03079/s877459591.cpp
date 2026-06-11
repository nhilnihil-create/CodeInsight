#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf(A == B && B == C ? "Yes\n" : "No\n");
	return 0;
}
