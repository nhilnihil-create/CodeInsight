#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	int T;
	ll a,b,c,d;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if (d<b || a<b) {printf("No\n");continue;}
		ll x=(a%b);
		ll cha=(d%b);
		if (x>c && x<b || x+d<b) {printf("No\n");continue;}
		if (cha==0) 
		{
			if (a>=b)printf("Yes\n");
			else printf("No\n");
			continue;
		}
		else
		{
			ll t;
			if (c>=x)
			{
				t=(c-x)/cha+1;
				t=x+t*cha;
				if (t-cha>c)
				t-=cha;	
			}
			else t=x;
			ll ans=t;
			for(int i=1;i<=10000;i++)
			{
				if (t>=b)
				{
					x=t-b;
					t=(c-x)/cha+1;
					t=x+t*cha;
					if (t-cha>c)
					t-=cha;
					ans=min(ans,t);
				}
				else break;
			}
			if (ans<b)
			printf("No\n");
			else printf("Yes\n");
		}
	}
}

/* 14 9 7 13 */