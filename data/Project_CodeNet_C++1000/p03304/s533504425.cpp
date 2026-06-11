#include "bits/stdc++.h"

using namespace std;
int main() {
	double n, m, d;
	cin >> n >> m >> d;
	double ans = (m - 1.0)*(n - d);
	if (d != 0) {
		ans *= 2.0;
	}
	ans /= n;
	ans /= n;
	printf("%.10f\n", ans);
}
