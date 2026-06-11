#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}	
	int ok=n,ng=0;
	while(abs(ok-ng)>1)
	{
		int mid=(ok+ng)/2,f=1;
		map<int,int> mp;
		mp[0]=0;
		mp[a[0]]=0;
		for (int i = 1; i < n; ++i)
		{
			if (a[i-1]<a[i])
			{
				if (mp.find(a[i])!=mp.end())
				{
					++mp[a[i]];
				}
				else
				{
					mp[a[i]]=0;
				}
			}	
			else
			{
				if (mp.upper_bound(a[i])!=mp.end())
				{
					mp.erase(mp.upper_bound(a[i]),mp.end());
					++mp[a[i]];
				}
				else
				{
					if (mp.find(a[i])!=mp.end())
					{
						++mp[a[i]];
					}
					else
					{
						mp[a[i]]=0;
					}
				}
				int now=a[i],cnt=0;
				auto itr=mp.lower_bound(a[i]);
				while (itr!=mp.begin())
				{
					if (itr->first!=now-cnt)
					{
						break;
					}
					if ((itr->first==now&&itr->second<mid)||(itr->first!=now&&itr->second<mid-1))
					{
						break;
					}
					if (mid==1)
					{
						mp[0]=1;
						break;
					}
					--itr;
					++cnt;
				}
				++itr;
				mp.erase(itr,mp.end());
				if (cnt>0)
				{
					++mp[now-cnt];
				}
				if (mp[0]>0)
				{
					f=0;
					break;
				}
				if (mp.find(a[i])==mp.end())
				{
					mp[a[i]]=0;
				}
			}
			if (f==0)
			{
				break;
			}
		}
		if (f)
		{
			ok=mid;
		}
		else
		{
			ng=mid;
		}
	}
	cout<<ok<<endl;
	return 0;
}
