#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
int x[N],n,X,y[N];
ll Solve(int mid)
{
	int i;
	ll ans=0;
	for(i=n;i>=1;i--)
	{
		if((n-i)%mid==0) y[i]=y[i+1]+1;
		else y[i]=y[i+1];
		if(y[i]==1) ans+=(ll)2*x[i];
		ans+=(ll)(y[i]+1)*(y[i]+1)*x[i]-(ll)y[i]*y[i]*x[i];
	}
	return ans+(ll)mid*X+(ll)n*X;
}
int main()
{
    int i;
    scanf("%i %i",&n,&X);
    for(i=1;i<=n;i++) scanf("%i",&x[i]);
    int top=n-1,bot=1,mid;
    ll ans=Solve(n);
    while(top>=bot)
	{
		mid=top+bot>>1;
		ll x=Solve(mid),y=Solve(mid+1);
		if(x<y) ans=x,top=mid-1;
		else bot=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}