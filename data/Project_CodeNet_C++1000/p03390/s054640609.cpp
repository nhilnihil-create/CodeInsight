#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		long long a,b;
		scanf("%lld %lld",&a,&b);
		long long lo =0, hi = 2e9;
		long long c = 0;
		while(lo <= hi)
		{
			long long mid = (lo + hi) >> 1;
			if(mid * mid < a*b)
			{
				c = mid;
				lo = mid+1;
			}
			else
			{
				hi = mid-1;
			}
		}
		long long ans = 2*c;
		if(a <= c)
			ans--;
		if(b <= c)
			ans--;
		if(c*(c+1) >= a*b)
			ans--;
		printf("%lld\n",ans);
	}
	return 0;
}
