#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int T;
inline bool solve () {
	long long A, B, C, D;
	scanf ("%lld%lld%lld%lld", &A, &B, &C, &D);
	if (A < B) return false;
	if (D < B) return false;
	if (C >= B - 1) return true;
	long long x = __gcd (B, D);
	A %= x; // num = kx + A
	long long k1 = C / x;
	if (k1 * x + A > C) k1--;
	if ((k1 + 1) * x + A < B) return false;
	return true;
}
int main () {
	scanf ("%d", &T);
	while (T--) printf (solve () ? "Yes\n" : "No\n");
	return 0;
}