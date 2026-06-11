#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
int main()
{
	int q;scanf("%d",&q);
	while(q--)
	{
		LL a,b,m;scanf("%lld %lld",&a,&b);
		m=a*b;
		LL l=1,r=sqrt(m)+10;
		while(l<=r)
		{
			LL mid=l+r>>1;
			if(mid*mid<=m-1) l=mid+1;
			else r=mid-1;
		}
		LL M=l-1,ans=M*2LL,t;
		if(a!=b)
		{
			if(a<=M) ans--;
			if(b<=M) ans--;
			if(m%M==0) t=m/M-1;
			else t=m/M;
			if(t==M) ans--;
		}
		printf("%lld\n",ans);
	}
}