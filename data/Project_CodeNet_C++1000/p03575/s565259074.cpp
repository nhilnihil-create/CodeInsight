#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MP make_pair
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PLI pair<ll, int>
#define PIL pair<int, ll>
#define STR string
#define Fst first
#define Snd second
#define SHN 1e9
#define LSHN 1e18
using namespace std;
int n,m;
vector<PII> v[500010];
bool isb[500010],vis[500010];
int Low[500010],dep[500010];
int tac; 
void dfs(int x,int par)
{
	vis[x]=1,dep[x]=++tac;
	Low[x]=dep[x];
	for (int i=0;i<v[x].size();i++)
	{
		int xi=v[x][i].Fst,yi=v[x][i].Snd;
		if (yi==par) continue;
		if (!vis[xi])
		{
			dfs(xi,yi);
			Low[x]=min(Low[x],Low[xi]);
		}
		else Low[x]=min(Low[x],dep[xi]);
	}
	//cout <<x<<" "<<dep[x]<<" "<<Low[x]<<" ##\n";
	if (x) isb[par]=(Low[x]==dep[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		v[x].push_back(MP(y,i));
		v[y].push_back(MP(x,i));
	}
	dfs(0,-1);
	printf("%d",count(isb,isb+m,1));
	return 0;
} 