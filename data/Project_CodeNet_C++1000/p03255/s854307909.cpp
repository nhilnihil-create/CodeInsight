#include<bits/stdc++.h>
#define ll  long long 
using namespace std;
const int MAXN=2e5+10;
const ll MAX=1e18;
ll a[MAXN];
ll n,x,ans;
int main()
{
	scanf("%lld%lld",&n,&x);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]=a[i-1]+a[i];
	};
	ans=MAX;
	for (int i=1;i<=n;i++)
	{
		ll w=x*n;
		w+=(a[n]-a[n-i])*5;
		w+=x*(ll)i;
		ll sum=5;
		for (int j=2;j<=n/i;j++)
		 {
		 	w+=(a[n-(j-1)*i]-a[n-j*i])*sum;
		 	if (w>ans) break;
		 	sum+=2;
		 }
		if (n%i!=0) w+=a[n%i]*sum;
		ans=min(ans,w); 
	}
	printf("%lld",ans);
}