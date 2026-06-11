#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n;
	scanf("%d", &n);
	if (n & 1) {
		printf("%d\n", n * (n - 2) / 2 + 1);
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (i + j != n)
					printf("%d %d\n", i, j);
			}
        }
	} 
    else {
        printf("%d\n", n * (n - 2) / 2);
		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (i + j != n + 1)
					printf("%d %d\n", i, j);
			}
        }
	}
}
