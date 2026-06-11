#include<iostream>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int a[3000];
	int ans = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		ans += a[i] - 1;
	}
	printf("%d\n", ans);
	return 0;
}
