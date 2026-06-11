#include <bits/stdc++.h>
using namespace std;

multiset<int> edge[100005],redge[100005];
vector<int> order;
int ans[100005];

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	int a,b;
	for (int i = 0; i < n+m-1; ++i)
	{
		cin>>a>>b;
		edge[a].insert(b);
		redge[b].insert(a);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (redge[i].size()==0)
		{
			redge[i].insert(0);
			edge[0].insert(i);
			break;
		}
	}
	queue<int> que;
	que.push(0);
	while (que.size()>0)
	{
		int now=que.front();que.pop();
		for (auto v:edge[now])
		{
			redge[v].erase(now);
			if (redge[v].size()==0)
			{
				que.push(v);
				ans[v]=now;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
