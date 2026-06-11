#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;
//const int M=50万;
const int N=132;
int n,m,low[N],dep[N];vi v[N];
int dfs(int now,int fa)
{
	low[now]=dep[now];
	int res=0;
	for(int i=0;i<v[now].size();i++)
	{
		int to=v[now][i];
		if(to==fa)continue;
		if(!dep[to])
		{
			dep[to]=dep[now]+1;
			res+=dfs(to,now);
			low[now]=min(low[now],low[to]);
		}else low[now]=min(low[now],dep[to]);
	}
	if(low[now]==dep[now])res++;
	return res;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--,b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	dep[0]=1;
	cout<<dfs(0,-1)-1<<"\n";
}