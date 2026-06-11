#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
char s[N];
int main()
{
	int n,q,k;
	scanf("%d%s%d",&n,s+1,&q);
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
