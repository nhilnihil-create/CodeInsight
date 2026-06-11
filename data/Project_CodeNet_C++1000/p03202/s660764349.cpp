#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
int n, a[maxn + 3];

bool check(int k) {
	map<int, int> M;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= a[i - 1]) {
			if (k == 1) {
				return false;
			}
			while (!M.empty() && M.rbegin() -> first > a[i]) {
				map<int, int>::iterator it = M.end();
				M.erase(--it);
			}
			for (int j = a[i]; j >= 0; j--) {
				if (j == 0) {
					return false;
				}
				if (++M[j] == k) {
					M[j] = 0;
				} else {
					break;
				}
			}
		}
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int l = 1, r = n, mid;
	while (l < r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	printf("%d\n", l);
	return 0;
}