/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++) 
#define LL long long
#define pii pair <LL,LL>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

LL n,d[100010],sonn[100010],dp[100010];
map <LL,LL> mp;
vector <LL> g[100010];
vector <pii> ans,v;
bool vis[100010];

bool cmp(pii a,pii b)
{
	return a.fi>b.fi;
}

void dfs(LL pos,LL no)
{
	if(vis[pos])
	{
		puts("-1");
		exit(0);
	}
	sonn[pos]=1;
	vis[pos]=true;
	rep(i,g[pos].size())
	{
		if(g[pos][i]==no) continue;
		dfs(g[pos][i],pos);
		dp[pos]+=dp[g[pos][i]]+sonn[g[pos][i]];
		sonn[pos]+=sonn[g[pos][i]];
	}
}

void dfs2(LL pos,LL no,LL now)
{
	if(now+dp[pos]!=d[pos])
	{
		puts("-1");
		exit(0);
	}
	rep(i,g[pos].size()) 
	if(g[pos][i]!=no) dfs2(g[pos][i],pos,now+dp[pos]-dp[g[pos][i]]-sonn[g[pos][i]]+n-sonn[g[pos][i]]);
}

int main()
{
	rep(i,100005) sonn[i]=1;
	cin>>n;
	rep(i,n)
	{
		scanf("%lld",&d[i]);
		mp[d[i]]=i;
		v.pb({d[i],i});
	}
	sort(v.begin(),v.end(),cmp);
	rep(i,v.size()-1)
	{
		LL wantpar=v[i].fi-n+sonn[v[i].se]*2;
		if(wantpar>=v[i].fi||mp.find(wantpar)==mp.end())
		{
			puts("-1");
			rt0;
		}
		sonn[mp[wantpar]]+=sonn[v[i].se];
		ans.pb({v[i].se,mp[wantpar]});
		g[v[i].se].pb(mp[wantpar]);
		g[mp[wantpar]].pb(v[i].se);
	}
	memset(sonn,0,sizeof(sonn));
	dfs(0,0);
	dfs2(0,0,0);
	rep(i,n-1) cout<<ans[i].fi+1<<' '<<ans[i].se+1<<endl;
	rt0;
}