#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(pair<ll,ll>a,pair<ll,ll>b)
{
	if(a.first!=b.first)return a.first>b.first;
	return a.second<b.second;
}

int main()
{
	int n,k;
	cin >> n >> k;
	vector<pair<ll,ll>> cmt,a,b;
	map<ll,ll> mp;
	for(int i = 0;i<n;i++)

	{
		ll x,y;
		cin >> x >> y;
		cmt.emplace_back(y,x);
	}
	sort(cmt.begin(),cmt.end(),cmp);
	for(int i = 0;i<n;i++)
	{
		ll x;
		x = cmt[i].second;
		ll y ;
		y = cmt[i].first;
		if(mp[x]==0)
		{
			a.emplace_back(y,x);
			mp[x] = true;
		}
		else
		{
			b.emplace_back(y,x);
		}
	}
	set<int> st;
	
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end(),cmp);
	vector<ll> asum(a.size()+1),bsum(b.size()+1);
	for(int i = 0;i<a.size();i++)
	{
		asum[i+1] += a[i].first+asum[i];
	}
	for(int i = 0;i<b.size();i++)
	{
		bsum[i+1] += b[i].first+bsum[i];
	}
	ll ans = 0;
	set<ll> A,B;
	
	for(int i = 1;i<=k;i++)
	{
		ll now = 0;

		if(i<asum.size())
		{
			now += asum[i];
			A.insert(a[i-1].second);
			if(B.find(a[i-1].second)!=B.end())
			{
				B.erase(B.find(a[i-1].second));
			}
		}
		else continue;
		if(k-i<bsum.size())
		{
			now += bsum[k-i];
			if(A.find(a[i-1].second)==A.end())B.insert(b[i-1].second);
		}
		else continue;
		ll x = A.size()+B.size();
		now += x*x;
		ans = max(ans,now);
	}
	cout<<ans<<endl;


}