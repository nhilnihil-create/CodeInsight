#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	multiset<long long> memo;
	long long a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		memo.insert(a[i]);
	}
	sort(a,a+n);
	reverse(a,a+n);
	long long now=1LL;
	while (now<=a[0])
	{
		now*=2LL;
	}
	long long ans=0LL;
	for (int i = 0; i < n; ++i)
	{
		while (now>a[i]*2LL)
		{
			now/=2LL;
		}
		int cnt=memo.count(a[i]),cnt2=memo.count(now-a[i]);
		if (cnt==0)
		{
			continue;
		}
		if (now==a[i]*2LL)
		{
			if (cnt>1)
			{
				for (int j = 0; j < cnt/2; ++j)
				{
					++ans;
					memo.erase(memo.lower_bound(a[i]));
					memo.erase(memo.lower_bound(a[i]));
				}
			}
			else if (cnt==1)
			{
				memo.erase(memo.lower_bound(a[i]));
			}
		}
		else if (cnt>0&&cnt2>0)
		{
			for (int j = 0; j < min(cnt,cnt2); ++j)
			{
				++ans;
				memo.erase(memo.lower_bound(a[i]));
				memo.erase(memo.lower_bound(now-a[i]));
			}
		}
		else
		{
			for (int j = 0; j < cnt; ++j)
			{
				memo.erase(memo.lower_bound(a[i]));
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
