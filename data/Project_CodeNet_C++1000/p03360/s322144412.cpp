#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int a[3];
	for (int i = 0; i < 3; i++) {
		scanf("%d", &a[i]);
	}
	int K;
	scanf("%d", &K);
	sort(a, a + 3);
	printf("%d\n", a[0] + a[1] + a[2]*(int)pow(2., (double)K));
	return 0;
}
