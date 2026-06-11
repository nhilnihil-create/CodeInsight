#include <bits/stdc++.h>
using namespace std;

int memo[2][200005],p[2]={},ma[2]={};
multiset<int> edge[200005];

void dfs(int now,int phase)
{
	for (auto i = edge[now].begin(); i != edge[now].end(); ++i)
	{
		if (memo[phase][*i]==-1)
		{
			memo[phase][*i]=memo[phase][now]+1;
			if (memo[phase][*i]>ma[phase])
			{
				ma[phase]=memo[phase][*i];
				p[phase]=*i;
			}
			dfs(*i,phase);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a,b;
	for (int i = 0; i < n-1; ++i)
	{
		cin>>a>>b;--a;--b;
		edge[a].insert(b);
		edge[b].insert(a);
	}
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			memo[i][j]=-1;
		}
	}
	memo[0][0]=0;
	dfs(0,0);
	memo[1][p[0]]=0;
	dfs(p[0],1);
	if (ma[1]%3==1)
	{
		cout<<"Second\n";
	}
	else
	{
		cout<<"First\n";
	}
	return 0;
}
