#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
long long a, b, c, d;
inline long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x%y); }
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if (a < b || d < b)
		{
			puts("No");
			continue;
		}
		if (c + 1 >= b)
		{
			puts("Yes");
			continue;
		}
		long long g = gcd(b, d);
		long long x = a - b;
		long long y = a - c - 1;
		if (x / g - y / g >= 0)	puts("Yes");
		else puts("No");
	}
	return 0;
}