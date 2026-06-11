#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long n, a, b, k, i;
int main()
{
	cin >> n;
	while (n--) {
		scanf ("%lld %lld", &a, &b);
		k = sqrt(a * b);
		if (a != b && k * k == a * b) k--;
		if (k * (k + 1) < a * b) printf("%lld\n", k * 2 - 1);
		else printf("%lld\n", k * 2 - 2);
	}
    return 0;
}
