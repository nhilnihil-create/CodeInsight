//baka wrong answer
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#define LL long long
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define abs(a) (((a)<0)?(-(a)):(a))
LL num1[1000000],num2[1000000],ans1[1000000],ans2[1000000];
LL p1[1000000],p2[1000000],far[1000000],del[1000000];

bool cmp1(const LL &a,const LL &b)
{
	return a>b;
}
bool cmp2(const LL &a,const LL &b)
{
	if (num2[a]==num2[b])
	{
		return num1[a]<num1[b];
	}
	return num2[a]<num2[b];
}

int main()
{
	//freopen("in.in","r",stdin);
	LL i,j,k,a,b,c,ans,n,pp1,pp2,rem,ans1,ans2;
	scanf("%lld",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%lld%lld",&num1[i],&num2[i]);
	}
	std::sort(num1+1,num1+n+1,cmp1);
	std::sort(num2+1,num2+n+1);

	if (num1[1]<=0) if (num2[1]>=0) {printf("0\n");return 0;}
	ans=0;i=1;j=1;a=0;ans1=0;ans2=0;
	if (num1[1]>0)
	{
		while (1)
		{
			if (i>n) {break;}
			if (num1[i]<=a) {break;}
			ans+=abs(num1[i]-a);a=num1[i];
			i+=1;
			if (j>n) {break;}
			if (num2[j]>=a) {break;}
			ans+=abs(num2[j]-a);a=num2[j];
			j+=1;
		}
		ans+=abs(a);
		ans1=ans;
	}
	ans=0;i=1;j=1;a=0;
	if (num2[1]<0)
	{
		while (1)
		{
			if (j>n) {break;}
			if (num2[j]>=a) {break;}
			ans+=abs(num2[j]-a);a=num2[j];
			j+=1;
			if (i>n) {break;}
			if (num1[i]<=a) {break;}
			ans+=abs(num1[i]-a);a=num1[i];
			i+=1;
		}
		ans+=abs(a);
		ans2=ans;
	}
	ans=max(ans1,ans2);
	//printf("%llu %llu %llu\n",a,b,i);
	printf("%llu\n",ans);
	return 0;
}