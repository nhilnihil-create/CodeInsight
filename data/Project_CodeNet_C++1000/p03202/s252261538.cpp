#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=2e5+5;
 
int n;
int a[N];
 
bool inc(int k, vector<pair<int, int> > &v)
{
	vector<pair<int, int> > temp;
	int cur=0;
	while(v.size() && v.back().first==k)
	{
		temp.push_back(v.back());
		v.pop_back();
	}
	if(!v.size())
		return 0;
	if(v.back().second>=2)
	{
		v[v.size()-1].second-=1;
		int cur=v.back().first;
		v.push_back({cur+1, 1});
	}
	else
		v[v.size()-1].first+=1;
	while(temp.size())
	{
		v.push_back({1, temp.back().second});
		temp.pop_back();
	}
	return 1;
}
 
int check(int k)
{
	vector<pair<int, int> > v;
	v.push_back({1, a[1]});
	int len=a[1];
	for(int i=2;i<=n;i++)
	{
		int sz=v.size();
		if(a[i]>a[i-1])
			v.push_back({1, a[i]-a[i-1]});
		else if(a[i]==a[i-1])
		{
			if(!inc(k, v))
				return 0;
		}
		else
		{
			while(v.size())
			{
				if(len-v.back().second>=a[i])
				{
					len-=v.back().second;
					v.pop_back();
				}
				else
					break;
			}
			v[v.size()-1].second-=(len-a[i]);
			if(!inc(k, v))
				return 0;
		}
		len=a[i];
	}
	return 1;
}
 
int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	return lo;
}
 
int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=binsearch(1, n);
	cout<<ans;	
	return 0;
}