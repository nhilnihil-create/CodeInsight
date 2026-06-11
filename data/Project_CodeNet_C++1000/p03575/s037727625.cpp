#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define pii pair<int,int>
#define vvi vector<vector<int> >
#define vpi vector<pii>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define lowbit(x) x&(-x)
#define N 55
using namespace std;
int n,m,cnt=0,num=0,dfsnum[N],low[N];
vector<int> edge[N];
void dfs(int x,int par)
{
	dfsnum[x]=++num;
	low[x]=dfsnum[x];
	for(int i=0;i<edge[x].size();i++)
	{
		if(edge[x][i]==par) continue;
		if(!dfsnum[edge[x][i]])
		{
			dfs(edge[x][i],x);
			low[x]=min(low[x],low[edge[x][i]]);
		}
		else low[x]=min(low[x],dfsnum[edge[x][i]]);
	}
	if(low[x]==dfsnum[x]) cnt++;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(1,-1);
	cout<<cnt-1<<endl;
	return 0;
}