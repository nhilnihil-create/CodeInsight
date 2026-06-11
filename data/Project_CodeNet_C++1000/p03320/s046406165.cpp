#if 1

#include <bits/stdc++.h>
long long n,i,d = 1,s;
long long f(long long p)
{
	for(s = 0;p >= 1;p /= 10) s += p % 10;
	return s;
}

int main()
{
	scanf("%lld", &n);
	while(n--)
    {
		if((i+d) * f(i+d*2) > (i+d*2) * f(i+d)) d *= 10;
		i += d;
		printf("%lld\n",i);
	}
    return 0;
}

#endif // 1++
