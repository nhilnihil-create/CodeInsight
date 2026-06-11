#include <cstdio>
#include <algorithm>

using namespace std;

long long A[300003], X[300003];

int main() {
	int i, j, n, m, a, b;
	scanf("%d%d%d", &n, &a, &b);
	if (a + b > n + 1 || (long long)a * b < n) {
		puts("-1");
		return 0;
	}
	n -= a + b - 1;
	m = 0;
	for (i = 0; i < a; i++) for (j = 0; j < b; j++) {
		if (i == 0 || j == 0 || n) {
			A[m] = X[m] = (long long)i * 1000000 - j;
			m++;
			if (i && j) n--;
		}
		else break;
	}
	sort(X, X + m);
	for (i = 0; i < m; i++) printf("%d ", upper_bound(X, X + m, A[i]) - X);
	return 0;
}
