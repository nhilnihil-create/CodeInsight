//**************************
//*** writer  :  Alan Hu **
//************************
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<list>
#include<stack>
#include<cstdio>
#include<fstream>
#include<numeric>
#include<functional>
#include<utility>
#include<memory>
#include<cstring>
#include<cmath>

using namespace std;
     
#define CLEAN(a,b) memset(a,b,sizeof(a))
#define mkp make_pair
#define pb push_back
#define rept(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
     
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX=2e5+10;
int l[MAX],r[MAX],d[MAX];
vi adj[MAX],edg[MAX];
bool vis[MAX];
int cnt[MAX];

void dfs(int v)
{
	vis[v]=true;
	rept(i,0,adj[v].size())
	{
		int u=adj[v][i];
		if (vis[u] && (cnt[u]!=edg[v][i]+cnt[v]))
    	{
    		cout<<"No";
    		exit(0);
    	}
    	if (!vis[u])
		{
			cnt[u]=cnt[v]+edg[v][i];
			dfs(u);
		}
	}
}

int n,m;

int main()
{
	cin>>n>>m;
	rept(i,1,m+1) 
	{
		cin>>l[i]>>r[i]>>d[i];
		adj[l[i]].pb(r[i]);
		adj[r[i]].pb(l[i]);
		edg[l[i]].pb(d[i]);
		edg[r[i]].pb(-d[i]);
	}
	rept(i,1,n+1)
	{
		if (!vis[i]) dfs(i);
	}
	cout<<"Yes"<<endl;
	return 0;
}