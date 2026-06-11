#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int N, X;
	scanf("%d %d", &N, &X);
	int m[100];
	int mMin = 100100;
	for (int i = 0; i < N; i++) {
		scanf("%d", &m[i]);
		X -= m[i];
		mMin = min(mMin, m[i]);
	}
	printf("%d\n", N + X / mMin);

	return 0;
}
