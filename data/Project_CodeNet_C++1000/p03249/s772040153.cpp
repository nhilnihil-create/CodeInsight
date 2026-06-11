#include<bits/stdc++.h>
using namespace std;

#define int long long

#define pii pair<int,int> 

int N;
int a[100010];
map<int,int> mp;

vector<pii> e;
int sz[100010];
int dp[100010];

vector<pii> ans;

bool cmp_d(pii p,pii q)
{
	return p>q;
}

pii norm(int p,int q)
{
	return {min(p,q),max(p,q)};
}

main()
{
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>a[i];
		mp[a[i]]=i;
		e.push_back({a[i],i});
		sz[i]=1;
	}
	sort(e.begin(),e.end(),cmp_d);
	int x=e.back().first;
	for(int i=0;i<e.size();i++)
	{
		pii& cur=e[i];
		if(cur.first!=x)
		{
			if(sz[cur.second]*2>=N) goto FAIL;
			int p=cur.first-N+2*sz[cur.second];
			if(mp.find(p)==mp.end()) goto FAIL;
			int q=mp[p];
			dp[q]+=dp[cur.second]+sz[cur.second];
			sz[q]+=sz[cur.second];
			ans.push_back(norm(cur.second,q));
		}
	}
	if(dp[e.back().second]!=x) goto FAIL;
	
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
	
	
	
	FAIL:;
	{
		cout<<"-1"<<endl;
		return 0;
	}
}






