#include<stdio.h>
int x[1024],y[1024];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	int tp=((x[0]+y[0])&1);
	tp^=1;
	for(int i=0;i<n;i++)
	{
		x[i]-=tp;
		if(((x[i]+y[i])&1)==0)
		{
			printf("-1\n");
			return 0;
		}
	}
	if(tp)
	{
		printf("36\n1 ");
	}
	else
	{
		printf("35\n");
	}
	for(int i=0;i<35;i++)
	{
		printf("%lld",(long long)1<<i);
		if(i==34)
		{
			putchar('\n');
		}
		else
		{
			putchar(' ');
		}
	}
	for(int i=0;i<n;i++)
	{
		if(tp)
		{
			putchar('R');
		}
		long long dx=x[i]-((long long)1<<35)+1;
		long long dy=y[i];
		dx=-dx;
		long long u=((dx+dy)>>1);
		long long d=((dx-dy)>>1);
		for(int j=0;j<35;j++)
		{
			if((u&((long long)1<<j))&&(d&((long long)1<<j)))
			{
				putchar('L');
			}
			else if(u&((long long)1<<j))
			{
				putchar('U');
			}
			else if(d&((long long)1<<j))
			{
				putchar('D');
			}
			else
			{
				putchar('R');
			}
		}
		putchar('\n');
	}
	return 0;
}