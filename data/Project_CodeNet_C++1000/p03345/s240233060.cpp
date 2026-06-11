#include<stdio.h>
int  main()
{
	long long a,b,c,k;
	while(~scanf("%lld %lld %lld %lld", &a, &b, &c, &k))
	{
		if(k/2 == (k+1)/2)
			printf("%lld\n", a-b);
		else
			printf("%lld\n", b-a);
	}
	return 0;
}