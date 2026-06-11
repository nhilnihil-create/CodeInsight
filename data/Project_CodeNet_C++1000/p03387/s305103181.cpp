#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int a[3];
	int aMax = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &a[i]);
		aMax = max(aMax, a[i]);
	}
	int diffSum = 0;
	for (int i = 0; i < 3; i++) {
		diffSum += aMax - a[i];
	}

	if (diffSum % 2 == 0) printf("%d\n", diffSum / 2);
	else printf("%d\n", diffSum / 2 + 2);

	return 0;
}
