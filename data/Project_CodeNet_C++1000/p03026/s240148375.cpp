#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> g[10000];
int ans[10000];
int aa;
vector<ll> c;
void dfs(int idx,int par = -1)
{
	ans[idx] = c[aa++];
	for(auto &i:g[idx])
	{
		if(i==par)continue;
		dfs(i,idx);
	}
}

ll dfs2(int idx,int par=-1)
{
	ll res = 0;
	for(auto &i:g[idx])
	{
		if(i==par)continue;
		res+= min(ans[i],ans[idx]);
		res += dfs2(i,idx);
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
//	vector<int > c(n);

	for(int i = 0;i<n-1;i++)
	{
		int x,y;
		cin >> x >> y;
		x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 0;i<n;i++)
	{
		int a;
		cin >> a;
		c.push_back(a);
	}
	sort(c.begin(),c.end(),greater<>());
	int idx;
	for(int i = 0;i<n;i++)if(g[i].size()==1)idx=i;
	dfs(idx);
	cout<<dfs2(idx)<<endl;
	for(int i = 0;i<n;i++)cout<<ans[i]<<' ';
	cout<<endl;

	return 0;
}