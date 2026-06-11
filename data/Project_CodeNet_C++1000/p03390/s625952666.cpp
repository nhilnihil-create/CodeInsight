#include <stdio.h>

long long sqrt(long long x)
{
	long long l = 0, r = 1000000001;
	while (l + 1 < r){
		long long m = (l + r) / 2;
		if (m * m <= x) l = m;
		else r = m;
	}
	return l;
}

int main()
{
	int Q; scanf ("%d",&Q); while (Q--){
		long long a,b; scanf ("%lld %lld",&a,&b);
		long long s = a * b - 1, q = sqrt(s);
		long long ans = q * 2;
		if (s){
			if (a <= q) ans--;
			if (b <= q) ans--;
			if ((a != q || b != q) && q == s / q) ans--;
		}
		printf ("%lld\n",ans);
	}

	return 0;
}