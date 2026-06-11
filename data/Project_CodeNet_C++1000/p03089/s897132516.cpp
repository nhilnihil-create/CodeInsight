#include <bits/stdc++.h>
using namespace std;

int a[110], b[110];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", b + i);
	}
	for (int i = n; i; --i) {
		bool is = false;
		for (int j = i; j; --j) {
			if (b[j] > j) break;
			if (b[j] == j) {
				a[i] = j;
				for (int k = j; k < i; ++k) {
					b[k] = b[k + 1];
				}
				is = true;
				break;
			}
		}
		if (!is) {
			puts("-1");
			return 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", a[i]);
	}
}