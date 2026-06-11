#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	long long luca[100];
	luca[0] = 2;
	luca[1] = 1;
	for (int i = 2; i <= N; i++) {
		luca[i] = luca[i - 1] + luca[i - 2];
	}
	printf("%lld\n", luca[N]);
	return 0;
}
