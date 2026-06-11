#include<bits/stdc++.h>
using namespace std;
#define md 1000000007
#define ll long long 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fastmap mp.reserve(1024);mp.max_load_factor(0.25);
#define fastset st.reserve(1024);st.max_load_factor(0.25);
ll int mpw(ll int a,ll int b,ll int m)
{
	ll int ans=1;
	if(a==0)return 0;
	if(a==1 || b==0)return 1;
	while(b)
	{
		if(b&1)
		{
			ans=(ans*a)%m;
		}
		a=(a*a)%m;
		b>>=1;
	}
	return ans;
}
 
ll int pw(ll int a,ll int b)
{
	ll int ans=1;
	if(a==0)return 0;
	if(a==1 || b==0)return 1;
	while(b)
	{
		if(b&1)
		{
			ans*=a;
		}
		a*=a;
		b>>=1;
	}
	return ans;
}
 
ll int mn(ll int a,ll int b)
{
	if(a<=b)
	{
		return a;
	}
	return b;
}
 
ll int mx(ll int a,ll int b)
{
	if(a>=b)
	{
		return a;
	}
	return b;
}
 
int main()
{
	fio
	int n;
	cin>>n;
	vector<vector<int>>g(n);
	for(int i=0;i<n-1;++i)
	{
		int a,b;
		cin>>a>>b;
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);
	}
	vector<bool>vis(n,false);
	vector<pair<ll int,ll int>>D(n,{0,0});
	std::function<void(int)>dfs=[&](int node)->void{
		int nm=0;
		vis[node]=true;
		ll int ans1=1,ans2=1;
		for(int i=0;i<g[node].size();++i)
		{
			if(!vis[g[node][i]])
			{
				nm++;
				dfs(g[node][i]);
				ans1=(ans1*((D[g[node][i]].first+D[g[node][i]].second)%md))%md;
				ans2=(ans2*D[g[node][i]].first)%md;
			}
		}
		if(nm==0)
		{
			D[node].first=1;
			D[node].second=1;
		}
		else{
			D[node].first=ans1;
			D[node].second=ans2;
		}
		return;
	};

	dfs(0);
	cout<<(D[0].first+D[0].second)%md<<"\n";
	return 0;
}