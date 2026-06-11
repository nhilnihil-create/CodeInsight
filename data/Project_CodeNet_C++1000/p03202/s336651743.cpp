#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
inline bool check(int x)
{
	if(x==1)
	{
		bool ch=true;
		for(int i=0;i<n-1;i++)
		{
			if(a[i+1]<=a[i])
			{
				ch=false;
			}
		}
		return ch;
	}
	map<int,int> mp;
	int cnt=-1;
	for(int i=0;i<n;i++)
	{
		if(a[i]<=cnt)
		{
			cnt=a[i];
			while(1)
			{
				if(mp[cnt]<x-1)
				{
					break;
				}
				mp[cnt]=0;
				cnt--;
			}
			mp[cnt]++;
			if(cnt<=0)
			{
				return false;
			}
		}
		else
		{
			cnt=a[i];
		}
		mp.erase(mp.upper_bound(cnt),mp.end());
	}
	return true;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int l=1,r=200005,ans;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid,r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}