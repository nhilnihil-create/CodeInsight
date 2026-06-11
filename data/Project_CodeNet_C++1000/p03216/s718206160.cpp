#include <bits/stdc++.h>
using namespace std;

int n,q,k;
char s[1000010];
long long ans,d,m,cnt;
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&k);
		ans=0;
		d=0;
		cnt=0;
		m=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='D')
			++d;
			if(s[i]=='M')
			{
				++m;
				cnt+=d;
			}
			if(s[i]=='C')
			ans+=cnt;
			if(i>=k)
			{
				if(s[i-(k-1)]=='D')
				{
					--d;
					cnt-=m;
				}
				if(s[i-(k-1)]=='M')
				--m;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}