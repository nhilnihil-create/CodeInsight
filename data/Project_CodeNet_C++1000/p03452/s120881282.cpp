#include <bits/stdc++.h>
using namespace std;

multiset<pair<int,int>> edge[100005];
int memo[100005],f=1;

void dfs(int now)
{
	for (auto v:edge[now])
	{
		if (memo[v.first]==1000000007)
		{
			memo[v.first]=memo[now]+v.second;
			dfs(v.first);
		}
		else if (memo[now]+v.second!=memo[v.first])
		{
			f=0;
		}
	}
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	int l,r,d;
	for (int i = 0; i < m; ++i)
	{
		cin>>l>>r>>d;--l;--r;
		edge[l].insert({r,d});
		edge[r].insert({l,-d});
	}
	for (int i = 0; i < n; ++i)
	{
		memo[i]=1000000007;
	}
	for (int i = 0; i < n; ++i)
	{
		if (memo[i]==1000000007)
		{
			memo[i]=0;
			dfs(i);
		}
	}
	if (f)
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
	return 0;
}
