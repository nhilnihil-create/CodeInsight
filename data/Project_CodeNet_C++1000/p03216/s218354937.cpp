#include <bits/stdc++.h>
using namespace std;
long long k[80];
char s[1000010];
int main()
{
	long long n,q,d,m,dm,i,j,ans;
	scanf("%lld",&n);
	scanf("%s",&s);
	scanf("%lld",&q);
	for(i=0;i<q;i++)
		scanf("%lld",&k[i]);
	for(i=0;i<q;i++)
	{
		d=m=dm=ans=0;
		for(j=0;j<n;j++)
		{
			if(j>=k[i])
			{
				if(s[j-k[i]]=='D')
				{
					d--;
					dm-=m;
				}
				if(s[j-k[i]]=='M')
					m--;
			}
			if(s[j]=='D')
				d++;
			if(s[j]=='M')
			{
				m++;
				dm+=d;
			}
			if(s[j]=='C')
				ans+=dm;
		}
		printf("%lld\n",ans);
	}
	return 0;	
}