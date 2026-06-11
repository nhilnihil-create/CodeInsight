#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	pair<pair<long long,long long>,int> l[n],r[n];
	long long a,b;
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b;
		l[i]={{b,a},i};
		r[i]={{-a,-b},i};
	}
	sort(l,l+n);
	sort(r,r+n);
	int memo[n]={},nl=0,nr=0;
	long long ans1=0LL,ans2=0LL,now=0LL;
	for (int i = 0; i < n; ++i)
	{
		if (i%2==0)
		{
			while(memo[l[nl].second]==1)
			{
				++nl;
			}
			memo[l[nl].second]=1;
			if (l[nl].first.second<=now&&now<=l[nl].first.first)
			{
				continue;
			}
			ans1+=abs(now-l[nl].first.first);
			now=l[nl].first.first;
		}
		else
		{
			while(memo[r[nr].second]==1)
			{
				++nr;
			}
			memo[r[nr].second]=1;
			if (-r[nr].first.first<=now&&now<=-r[nr].first.second)
			{
				continue;
			}
			ans1+=abs(now+r[nr].first.first);
			now=-r[nr].first.first;
		}
	}
	ans1+=abs(now);
	for (int i = 0; i < n; ++i)
	{
		memo[i]=0;
	}
	now=0LL;
	nl=0;
	nr=0;
	for (int i = 0; i < n; ++i)
	{
		if (i%2==1)
		{
			while(memo[l[nl].second]==1)
			{
				++nl;
			}
			memo[l[nl].second]=1;
			if (l[nl].first.second<=now&&now<=l[nl].first.first)
			{
				continue;
			}
			ans2+=abs(now-l[nl].first.first);
			now=l[nl].first.first;
		}
		else
		{
			while(memo[r[nr].second]==1)
			{
				++nr;
			}
			memo[r[nr].second]=1;
			if (-r[nr].first.first<=now&&now<=-r[nr].first.second)
			{
				continue;
			}
			ans2+=abs(now+r[nr].first.first);
			now=-r[nr].first.first;
		}
	}
	ans2+=abs(now);
	cout<<max(ans1,ans2)<<endl;
	return 0;
}
