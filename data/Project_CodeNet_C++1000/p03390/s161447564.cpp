#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define maxn 100005
using namespace std;
typedef long long ll;
int main()
{
	int _;
	scanf("%d",&_);
	while(_--)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ll temp=sqrt(x*y);
//		cerr<<"its ";
		if(temp*temp==x*y)
		{
			ll ans=2ll*temp;
			ans-=2;
			if(x!=y)
			ans--;
			printf("%lld\n",ans);
		}
		else
		{
			if(temp*(temp+1)>=x*y)
				printf("%lld\n",2ll*temp-2+1-1);
			else
				printf("%lld\n",2ll*temp-1);
		}
	}
}
