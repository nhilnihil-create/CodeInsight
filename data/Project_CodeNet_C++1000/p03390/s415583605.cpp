#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
LL Q;
LL a,b;
int main()
{
	/*LL n=1000;
	LL last=-1;
	for (LL u=1;u*u<=n;u++)
	{
		if (last==n/u) printf("NO\n");
		last=n/u;
		printf("%lld %lld\n",u,n/u);
	}*/
	scanf("%lld",&Q);
	while (Q--)
	{
		scanf("%lld%lld",&a,&b);
		LL n=a*b-1;
		if (a>b) swap(a,b);
		LL o=0;
		LL l=1,r=sqrt(n)+5;
		while (l<=r)
		{
			LL mid=(l+r)/2;
			if (mid*mid<=n) {o=mid;l=mid+1;}
			else r=mid-1;
		}
		if (o==0)
		{
			printf("0\n");
			continue;
		}
		LL ans=2*o;//先看一下有多少对答案
		if (o==(n/o)) ans--;
		//printf("%lld %lld\n",o,ans);
		LL g=(n/o)-o;//中间有多少个空格
		LL t=a-1;//如果b要配，那么肯定是配这一个
		if (a<=o)//如果是比这个大的 
			ans--;
		if (t==0)//你什么b没有参与配对，没有影响
			printf("%lld\n",ans);
		else
		{ 
			LL tt=n/t;
			if (tt!=b)  printf("%lld\n",ans);
			else
			{
				//printf("YES");
				//那么现在的状态就是t*b 
				if (g!=0) printf("%lld\n",ans);
				else
				{
					if (t==o)//如果刚好是最后一个
						printf("%lld\n",ans-1);
					else
					{
						tt=t+1;
						LL h=n/tt;
						if (b-h>1) printf("%lld\n",ans);
						else printf("%lld\n",ans-1);
					}
				}
			}
		}
	}
	return 0;
}