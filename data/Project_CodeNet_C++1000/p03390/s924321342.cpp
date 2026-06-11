#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef long long LL;
int main()
{
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		LL a,b;
		scanf("%lld %lld",&a,&b);
		LL c=sqrt(a*b);
		if(c*c==a*b)
			c--;
		LL ans=c*2-1;
		if(c*(c+1)>=a*b)
			ans--;
		LL i=2;
		while(c*(c+i)<a*b)
			i++; 
		if(a==b && c*(c+2)<a*b)
			ans++;
		printf("%lld\n",ans);
	}
	return 0;
 } 