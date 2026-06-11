#include<bits/stdc++.h>
using namespace std;
long long a[200009],xsum[200009],sum[200009],ll=1;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
		xsum[i]=xsum[i-1]^a[i];
	}
	long long ans=0;
	int l=n;
	for(int i=1;i<=n;i++)
	{
		if(sum[i]!=xsum[i])
		{
			l=i-1;
			break;
		}
	}
	ans=ll*l*(l+1)/2;
	for(int i=2;i<=n;i++)
	{
		if(l==n)break;
		int j;
		for(j=max(i+1,l+1);j<=n;j++)
		{
			if(sum[j]-sum[i-1]!=(xsum[j]^xsum[i-1]))
			{
				j--;
				break;
			}
		}
		j=min(j,n);
		ans+=ll*(j-i+2)*(j-i+1)/2;
		//cout<<ans<<" "<<l<<"  "<<i<<" "<<j<<"      ";
		if(i<=l)ans-=ll*(l-i+2)*(l-i+1)/2;
		l=j;
		//cout<<ans<<" "<<l<<"  "<<i<<" "<<j<<endl;
	}
	cout<<ans;
	return 0;
}