#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,m,dep[N],lw[N],din[N],ans,cnt=0;
bool vis[N];
vector<ll> vt[N],bri;
void dfs(ll x,ll lst)
{
	vis[x]=true;
	lw[x]=din[x]=++cnt;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			if(vis[vt[x][i]])
			{
				lw[x]=min(lw[x],din[vt[x][i]]);
			}
			else
			{
				dfs(vt[x][i],x);
				lw[x]=min(lw[x],lw[vt[x][i]]);
			}
		}
	}
	if(lw[x]==din[x]&&x!=0)
	{
		bri.push_back(x);
	}
	return;
}
int main(){
	ll i,x,y;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	dfs(0,-1);
	printf("%lld\n",(ll)bri.size());
	return 0;
}