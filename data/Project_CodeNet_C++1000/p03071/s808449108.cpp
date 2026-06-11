#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int A, B;
	scanf("%d%d", &A, &B);
	int ans = 0;
	for (int i = 0; i < 2; i++) {
		if (A >= B) {
			ans += A;
			A--;
		} else {
			ans += B;
			B--;
		}
	}
	printf("%d\n", ans);
	return 0;
}
