#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int d, n; scanf("%d%d", &d, &n);

	if (n == 100) ++n; // 100番目はDが繰り上がるため
	int ans = pow(100, d) * n;

	printf("%d\n", ans);
	return 0;
}