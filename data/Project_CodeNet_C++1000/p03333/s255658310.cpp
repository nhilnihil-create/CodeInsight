#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

namespace fake
{
	typedef long long ll;

	const int N=101000;

	int L[N],R[N];
	int n;

	void initialize()
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",L+i,R+i);
		std::sort(L+1,L+n+1),std::sort(R+1,R+n+1);
	}
	void solve()
	{
		initialize();

		ll ans=0,sum=0;

		for(int i=1;i<=n;i++)
		{
			ans=std::max(ans,(sum+L[n-i+1])*2);
			ans=std::max(ans,(sum-R[i])*2);

			sum=sum+L[n-i+1]-R[i];

			ans=std::max(ans,sum*2);
		}

		printf("%lld\n",ans);
	}
}

int main()
{
	fake::solve();
	return 0;
}
