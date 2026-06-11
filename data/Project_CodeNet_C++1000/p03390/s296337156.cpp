#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
ll q, n, a, b;
int main()
{
	cin >> q;
	while (q--) {
		scanf("%lld %lld", &a, &b);
		if (a == b) {printf("%lld\n", 2 * a - 2); continue;}
		n = sqrt(a * b);
		if (n * n == a * b) n--;
		if (n * (n + 1) < a * b) printf("%lld\n", 2 * n - 1);
		else printf("%lld\n", 2 * n - 2);
	}
    return 0;
}