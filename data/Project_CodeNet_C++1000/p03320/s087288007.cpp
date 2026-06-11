#include<cstdio>
#define LL long long
LL k;
double Cnt(LL i)
{
	LL t=i,cnt=0;
	while(t)
	{
		cnt+=t%10;
		t/=10;
	}
	return 1.0*i/cnt;
}
int main()
{
	scanf("%lld",&k);
	LL x=0,r=1;
	while(k--)
	{
		double x1=Cnt(x+r),x2=Cnt(x+r*10);
		while(1)
		{
			x1=Cnt(x+r),x2=Cnt(x+r*10);
			if(x1<=x2) break;
			r*=10;
		}
		x+=r;
		//printf("%lld ",r);
		printf("%lld\n",x);
	}
}