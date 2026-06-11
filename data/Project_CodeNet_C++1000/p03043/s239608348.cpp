#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n, k;
	cin >> n >> k;
	long double ans = 0.0;
	for (long long i = 1; i <= n; i++) {
		long long tmp = i;
		for (int m = 0; tmp < k; m++) {
			tmp *= 2;
		}
		ans += (long double)1.0 / (long double)(tmp/i);
	}
	printf("%.12Lf\n", ans/(long double)n);
	return 0;
}