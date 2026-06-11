#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	if (A == B) printf("%d\n", C);
	else if (B == C) printf("%d\n", A);
	else printf("%d\n", B);
	return 0;
}
