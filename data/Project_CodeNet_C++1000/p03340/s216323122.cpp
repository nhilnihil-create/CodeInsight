#include<bits/stdc++.h>
using namespace std;

int n,a[200010];
long long ans=0,tot,r=1;

#define rep(i,n) for(int i=1;i<=n;i++)
int main()
{
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	long long suma=0,sumb=0;
	rep(i,n)
	{
		while(  r<=n+1  &&  suma == sumb  )
		{
			suma^=a[r];
			sumb+=a[r];
			r++;
		}
		suma^=a[i]; sumb-=a[i];
		suma^=a[r-1]; sumb-=a[r-1];
		ans+=r-i-1;
		r--;
	}
	printf("%lld",ans);
	return 0;
} 