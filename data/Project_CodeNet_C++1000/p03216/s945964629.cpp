#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
char s[N];
int a[N],n,q,k;
inline int get_sum(int x,int y)
{
	if(y>n)	
		y=n;
	return a[y]-a[x-1];
}
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		a[i]=a[i-1]+(s[i]=='C');
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&k);
		long long ans=0,sd=0,sm=0,sdm=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='D')
				sd++;
			if(s[i]=='M')
				sm++,sdm+=sd;
			if(s[i]=='C')
				ans+=sdm;
			if(i<k)
				continue;
			if(s[i-k+1]=='D')
				sd--,sdm-=sm;
			if(s[i-k+1]=='M')
				sm--;
		}
		printf("%lld\n",ans);
	} 
	return 0;
}
