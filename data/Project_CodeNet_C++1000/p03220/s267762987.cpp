#include<iostream>
#include<stdio.h>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int T, A;
	scanf("%d %d", &T, &A);
	double tempMin = 1000000;
	int ans;
	for (int i = 0; i < N; i++) {
		int H;
		scanf("%d", &H);
		double diff = abs(A - (T - H * 0.006));
		if (diff < tempMin) {
			tempMin = diff;
			ans = i + 1;
		}
	}
	printf("%d\n", ans );

	return 0;
}
