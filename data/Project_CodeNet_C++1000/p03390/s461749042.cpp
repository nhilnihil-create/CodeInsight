#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

int N;
long long a, b, res;

bool check (long long);

int main () {
    scanf("%d", &N);
    for (int i = 1;i <= N; ++i) {
	scanf("%lld%lld", &a, &b);
	long long m = (long long)std :: sqrt(a * b);
	res = 2 * m - 1;
	if (m * m == a * b && a != b) res--;
	if (m * (m + 1) >= a * b) res--;
	printf("%lld\n", res);
    }
    return 0;
}
