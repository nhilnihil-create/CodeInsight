#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<pair<long long,int>>e;
	map<long long,int>ret;
	for(int i=0;i<n;i++)
	{
		long long x;
		cin>>x;
		ret[x]=i;
		e.push_back({x,i});
	}
	sort(e.rbegin(),e.rend());
	long long x=e.back().first;
	vector<int>sz(n,1);
	vector<long long>dp(n,0);
	vector<pair<int,int>>ans;
	for(auto c:e)
	{
		if(c.first!=x)
		{
			if(sz[c.second]*2>=n)
			{
				cout<<-1<<endl;
				return 0;
			}
			long long need=c.first-(n-2*sz[c.second]);
			if(!ret.count(need))
			{
				cout<<-1<<endl;
				return 0;
			}
			int par=ret[need];
			dp[par]+=dp[c.second]+sz[c.second];
			sz[par]+=sz[c.second];
			ans.push_back({c.second+1,par+1}); 
		}
	}
	if(dp[e.back().second]!=x)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(auto c:ans)
		cout<<c.first<<' '<<c.second<<endl;
	return 0;
}
