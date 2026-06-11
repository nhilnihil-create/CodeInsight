#include<bits/stdc++.h>
#include <functional>
#include <queue>
using namespace std;
using ll = long long;
vector<int> G[100000];
int Par[100000];
int n,m;
int tocnt[100000];
int root;
int depth[100000];

int dfs(int idx)
{
	if(depth[idx]!=0)return depth[idx];
	if(G[idx].empty())return depth[idx] = 1;
	for(auto &i:G[idx])
	{
		depth[idx] = max(depth[idx],dfs(i)+1);
	}
	return depth[idx];
}


int main()
{
	cin >> n >> m;
	for(int i = 0;i<n+m-1;i++)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		G[a].push_back(b);
		tocnt[b]++;
	}
	for(int i = 0;i<n;i++)
	{
		if(tocnt[i]==0)root = i;
	}
	map<pair<int,int>,bool> mp;
	using P = pair<int,int>;
	priority_queue<P,vector<P>,greater<P>> pq;
	pq.emplace(0,root);

	vector<P> vp;
	dfs(root);
	for(int i = 0;i<n;i++)
		vp.emplace_back(depth[i],i);

	sort(vp.begin(),vp.end(),greater<>());
	vector<int>depth2(n);

	for(int i =0;i<n;i++)
	{
		int now = vp[i].second;
		for(auto &j:G[now])
		{
			depth2[j] = depth2[now]+1;
		}
	}
	
	for(int i =0;i<n;i++)
	{
		for(auto j:G[i])
		{
			if(depth2[i]-depth2[j]==-1)
			{
				Par[j] = i;
			}
		}
	}
	
	Par[root] = -1;
	for(int i = 0;i<n;i++)cout << Par[i]+1 << endl;
}
