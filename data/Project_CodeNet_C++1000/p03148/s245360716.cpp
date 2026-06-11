#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int n,k;
	cin >> n >> k;
	ll ans = 0;
	vector<vector<int>> a(n);
	vector<pair<int,int>> vp(n);
	for(int i = 0;i<n;i++)
	{
		cin >> vp[i].first >> vp[i].second;
	}
	sort(vp.begin(),vp.end(),[&](auto a,auto b){return a.second>b.second;});
	map<int,int> mp;
	priority_queue<int,vector<int>,greater<int>> pq;
	ll sum = 0;
	ll v = 0;
	for(int i = 0;i<k;i++)
	{
		sum+= vp[i].second;
		if(mp.count(vp[i].first))
		{
			pq.push(vp[i].second);
		}
		mp[vp[i].first]++;
	}
	v = mp.size();
	ans = v*v+sum;
	for(int i = k;i<n;i++)
	{
		if(mp.count(vp[i].first)==0&&pq.size()>0)
		{
			sum -= pq.top();
			pq.pop();
			mp[vp[i].first]=1;
			v++;
			sum += vp[i].second;
			ans = max(ans,v*v+sum);
			
		}
	}
	cout<<ans<<endl;
}
