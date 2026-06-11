#include<stdio.h>

int main()
{
	long long int n, a,save, remind, a500=0, b =0, sum =0 ;

	scanf("%lld%lld", &n, &a);
	save = n;
		a500 = save / 500;
		remind = n % 500;
		if(remind >= 1)
			b = remind / 1;

		sum = b;

		if(sum <= a)
			printf("Yes\n");

		else
			printf("No\n");

		return 0;
}