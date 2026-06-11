#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010;

int n, m, a[N];

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a, a + n);

	int res = 0;

	for (int i = 0; i < n; i++) {
		int k = min(a[i], m);
		m -= k;
		a[i] -= k;
		res += ((a[i] == 0) ? 1 : 0);
	}

	if (m > 0) {
		--res;
	}

	printf("%d\n", res);

	return 0;

}