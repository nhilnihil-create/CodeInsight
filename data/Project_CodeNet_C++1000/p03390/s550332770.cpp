#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll find(ll x)
{
	ll lb=0,ub=2e9;
	while(ub>lb+1)
	{
		ll mid=(lb+ub)>>1;
		//printf("lb=%lld,ub=%lld,mid=%lld\n",lb,ub,mid);
		if(mid*mid<=x) lb=mid;
		else ub=mid;
	}
	//puts("gg");
	return lb;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ll A,B;
		scanf("%lld%lld",&A,&B);
		if(A==1&&B==1)
		{
			puts("0");
			continue;
		}
		if(A>B) swap(A,B);
		if(A==1&&B==2)
		{
			puts("0");
			continue;
		}
		ll ans=A-1;
		ll s=find(A*B-1);
		//printf("ans=%lld,t=%lld\n",ans,t);
		ans+=s; ll t=(A*B-1)/s;
		if(t==A) --ans;
		//printf("ans=%lld,s=%lld,t=%lld\n",ans,s,t);
		ans+=max(0LL,min(s-A,B-t)-(s==t?1:0));
		printf("%lld\n",ans);
	}		
	return 0;
}