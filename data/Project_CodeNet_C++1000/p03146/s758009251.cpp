#include<stdio.h>
int construct(int n)
{
	if(n%2) return 3*n+1;
	else return n/2;
}
int main()
{
	int s,i,a,b,c,d,count;
	while(~scanf("%d", &s))
	{
		a = s;
		b = construct(a);
		c = construct(b);
		count = 3;
		while(1)
		{
			count++;
			d = construct(c);
			if(d==a) break;
			a=b;b=c;c=d;
		}
		printf("%d\n", count);
	}
}