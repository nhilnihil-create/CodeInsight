#include <bits/stdc++.h>
using namespace std;

string s;
multiset<int> edge[200005];
int memo[200005][2];

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m>>s;
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		cin>>a>>b;
		--a;--b;
		if (edge[a].count(b)>0)
		{
			continue;
		}
		edge[a].insert(b);
		++memo[a][s[b]-'A'];
		if (a!=b)
		{
			edge[b].insert(a);
			++memo[b][s[a]-'A'];
		}
	}
	multiset<int> que;
	for (int i = 0; i < n; ++i)
	{
		if (memo[i][0]==0||memo[i][1]==0)
		{
			que.insert(i);
			while (que.size()>0)
			{
				int now=*que.begin();
				for (auto itr = edge[now].begin(); itr != edge[now].end();)
				{
					int v=*itr;
					itr=edge[now].erase(itr);
					--memo[now][s[v]-'A'];
					edge[v].erase(now);
					--memo[v][s[now]-'A'];
					if (memo[v][0]==0||memo[v][1]==0)
					{
						que.insert(v);
					}
				}
				que.erase(now);
			}
		}
	}
	int f=0;
	for (int i = 0; i < n; ++i)
	{
		if (edge[i].size()>0)
		{
			f=1;
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
