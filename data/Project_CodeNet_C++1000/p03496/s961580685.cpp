#include <bits/stdc++.h>
using namespace std;
int n;
int a[55];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) scanf("%d", &a[i]);
	int mx = -1e9, mxn;
	int mn = 1e9, mnn;
	for (int i = 0; i < n; ++ i) {
		if (a[i] > mx) mx = a[i], mxn = i;
		if (a[i] < mn) mn = a[i], mnn = i;
	}
	if (mx <= 0) {
		printf("%d\n", n - 1);
		for (int i = n - 1; i; -- i) {
			printf("%d %d\n", i + 1, i);
		}
		return 0;
	}
	if (mn >= 0) {
		printf("%d\n", n - 1);
		for (int i = 0; i + 1 < n; ++ i) {
			printf("%d %d\n", i + 1, i + 2);
		}
		return 0;
	}
	if (mx + mn >= 0) {
		printf("%d\n", 2 * n - 2);
		for (int i = 0; i < n; ++ i) if (i != mxn) {
			printf("%d %d\n", mxn + 1, i + 1);
		}
		for (int i = 0; i + 1 < n; ++ i) {
			printf("%d %d\n", i + 1, i + 2);
		}
	} else {
		printf("%d\n", 2 * n - 2);
		for (int i = 0; i < n; ++ i) if (i != mnn) {
			printf("%d %d\n", mnn + 1, i + 1);
		}
		for (int i = n - 1; i; -- i) {
			printf("%d %d\n", i + 1, i);
		}
	}
	return 0;
}