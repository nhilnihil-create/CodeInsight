#include<stdio.h>
int main()
{
	int a,b,c,x,i,j,k,temp,d,count;
	while(~scanf("%d %d %d %d", &a, &b, &c, &x))
    {
        count = 0;
		x/=50;
		for(i=0; i<=a; i++)
			for(j=0; j<=b; j++)
				for(k=0; k<=c; k++)
					if(i*10+j*2+k==x)
						count++;
		printf("%d\n", count);
    }

	return 0;
}
