#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	pair<long long,int> a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i].second>>a[i].first;
		--a[i].second;
	}
	sort(a,a+n);
	reverse(a,a+n);
	long long ans=0LL;
	int memo[n+5]={},x=0;
	for (int i = 0; i < k; ++i)
	{
		ans+=a[i].first;
		if (memo[a[i].second]==0)
		{
			++x;
		}
		++memo[a[i].second];
	}
	ans+=(long long)x*x;
	int del=k-1,ins=k;
	long long tmp=ans;
	while (del>=0&&ins<n)
	{
		while (del>=0&&memo[a[del].second]<=1)
		{
			--del;
		}
		if (del<0)
		{
			break;
		}
		tmp-=a[del].first;
		--memo[a[del].second];
		while (ins<n&&memo[a[ins].second]>0)
		{
			++ins;
		}
		if (ins>=n)
		{
			break;
		}
		tmp+=a[ins].first;
		++memo[a[ins].second];
		++x;
		tmp-=(long long)(x-1)*(x-1);
		tmp+=(long long)x*x;
		ans=max(ans,tmp);
		--del;
		++ins;
	}
	cout<<ans<<endl;
	return 0;
}
