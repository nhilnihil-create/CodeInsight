#include<bits/stdc++.h>
using namespace std;
int n,a,b,p[10005],i,j;
long long f[5005],s,ans=100000000000000ll;
int main()
{
	scanf("%d %d %d",&n,&a,&b);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&p[i]);
		f[i]=100000000000000ll;
	}
	for(i=1;i<=n;++i)
	{
		s=0;
		for(j=i-1;j>=0;--j)
		{
			if(p[i]>p[j])
				f[i]=min(f[i],f[j]+s);
			if(p[j]>p[i])
				s+=a;
			else
				s+=b;
		}
	}
	for(i=n;i>=0;--i)
	{
		s=0;
		for(j=i+1;j<=n;++j)
			s+=b;
		ans=min(ans,f[i]+s);
	}
	cout<<ans;
}
