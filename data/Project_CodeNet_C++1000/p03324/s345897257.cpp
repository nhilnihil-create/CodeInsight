#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int d, n; scanf("%d%d", &d, &n);

	int ans = pow(100, d) * n;
	if (n == 100) ans = pow(100, d) * (n + 1);

	printf("%d\n", ans);
	return 0;
}