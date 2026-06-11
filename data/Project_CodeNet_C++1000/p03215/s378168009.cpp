#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> num;
int main()
{
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	ll a[n+1],pre[n+1];
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	pre[0] = 0ll;
	for(i=1;i<=n;++i)
	{
		pre[i] = pre[i-1] + a[i];
	}
	ll maxi = 0ll;
	for(i=1;i<=n;++i)
	{
		for(j=i;j<=n;++j)
		{
			num.push_back(pre[j]-pre[i-1]);
			maxi = max(maxi,pre[j]-pre[i-1]);
		}
	}
	vector<bool> yes(num.size(),true);
//	for(i=0;i<num.size();++i)
//	{
//		printf("%d ",num[i]);
//	}
//	printf("\n");
	int max_bit = 0;
	while(maxi>0)
	{
		max_bit++;
		maxi/=2;
	}
//	printf("%d\n",max_bit);
	ll ans = 0ll;
	vector<int> x;
	for(i=max_bit;i>=0;i--)
	{
		int cnt = 0;
		for(j=0;j<num.size();++j)
		{
			if(yes[j]==true)
			{
				if((num[j] & (1ll<<i)) != 0)
				{
			//		printf("%d %d\n",num[j],1ll<<i);
					++cnt;
				}
				else	x.push_back(j);
			}
		}
		if(cnt>=m)
		{
			ans = ans + (1ll<<i);
		//	printf("%d\n",i);
			for(j=0;j<x.size();++j)
			{
				yes[x[j]] = false;
			}
		}
		x.clear();
	}
	printf("%lld",ans);
}