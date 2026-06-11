//************************
//*  Date: 2018.10.22    *
//*  Problem:            *
//*  Author: xuziyuan    * 
//************************

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++)
#define LL long long
#define pii pair<LL,LL>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

LL n,m,li,ri,k;
LL pos[100010];
vector <pii> g[100010];

void dfs(LL pos1,LL coo)
{
	if(pos[pos1]!=1e18&&pos[pos1]!=coo)
	{
		puts("No");
		exit(0);
	}
	if(pos[pos1]!=1e18) return;
	pos[pos1]=coo;
	rep(i,g[pos1].size()) dfs(g[pos1][i].fi,coo+g[pos1][i].se);
}

int main()
{
	cin>>n>>m;
	rep(i,100005) pos[i]=1e18;
	rep(i,m)
	{
		scanf("%d%d%d",&li,&ri,&k);
		g[li].pb({ri,k});
		g[ri].pb({li,-k});
	}
	repn(i,n)
	{
		if(pos[i]==1e18) dfs(i,0);
	}
	puts("Yes");
	rt0;
}