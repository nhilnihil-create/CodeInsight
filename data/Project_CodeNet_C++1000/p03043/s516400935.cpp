#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#include"bits/stdc++.h"
using namespace std;
using ld=long double;
int32_t main()
{
	int n,k;
	cin>>n>>k;
	ld ans=0;
	int cur;int tm;
	for(int i=1;i<=n;i++)
	{
		cur=i;tm=0;
		while(cur<k)
		{
			cur*=2;
			tm++;
		}
		ans+=(1/(ld)(1LL<<tm));
		
	}
	
	ans*=(1/(ld)n);
	
	cout<<fixed<<setprecision(12)<<ans;
	
}