#include <stdio.h>
#include <algorithm>

using namespace std;

int n, a[100000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	if (n == 2) {
		printf("%d %d\n", a[1], a[0]);
		return 0;
	}
	int lo = 0, hi = n - 2;
	if (a[lo] >= (a[n - 1] + 1) / 2) {
		printf("%d %d\n", a[n - 1], a[lo]);
		return 0;
	}
	if (a[hi] <= (a[n - 1] + 1) / 2) {
		printf("%d %d\n", a[n - 1], a[hi]);
		return 0;
	}
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (a[mid] <= (a[n - 1] + 1) / 2) lo = mid;
		else hi = mid;
	}
	if ((a[n - 1] + 1) / 2 - a[lo] > a[hi] - (a[n - 1] + 1) / 2) lo = hi;
	printf("%d %d\n", a[n - 1], a[lo]);
	return 0;
}