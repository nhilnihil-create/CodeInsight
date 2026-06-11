#include <stdio.h>
int main()
{
	long long a, b, c, d, e;
	scanf("%lld %lld", &a,&b);
	a = a - 1;
	if (a % 4 == 0) d = a;
	if (a % 4 == 1) d = 1;
	if (a % 4 == 2) d = a + 1;
	if (a % 4 == 3) d = 0;

	if (b % 4 == 0) c = b;
	if(b % 4 == 1) c = 1;
	if (b % 4 == 2) c = b + 1;
	if (b % 4 == 3) c = 0;
	if (a == -1) {
		printf("%lld", c);
		return 0;
	}
	e = c ^ d;
	printf("%lld", e);
}