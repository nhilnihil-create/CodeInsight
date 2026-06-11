#include<iostream>
#include<math.h>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int a[10010];
	int ans = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		while (a[i] % 2 == 0) {
			ans++;
			a[i] /= 2;
		}
	}
	printf("%d\n", ans);
}
