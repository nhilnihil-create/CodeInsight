/*
Though leaves are many, the root is one;
Through all the lying days of my youth
I swayed my leaves and flowers in the sun,
Now many I wither into the truth.
-- William Butler Yeats
µ±»ªÃÀµÄÒ¶Æ¬Âä¾¡£¬ÉúÃüµÄÂöÂç²ÅÀúÀú¿É¼û
*/ 
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
ll n;
ll d[100005];
map <ll,ll> m;
pair<ll,ll> p[100005];
ll sub[100005];
ll sz[100005];
vector <pair<ll,ll> >res;
vector <int>vec[100005];
ll dp[100005];

int dfs(int x,int p=-1)
{
	sz[x]=1;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]==p) continue;
		sz[x]+=dfs(vec[x][i],x);
	}
	return sz[x];
}

int go(int x,int p=-1)
{
	dp[x]=sz[x]-1;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]==p) continue;
		dp[x]+=go(vec[x][i],x);
	}
	return dp[x];
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		cin>>d[i];
		m[d[i]]=i;
		p[i].first=d[i];
		p[i].second=i;
		sz[i]=1;
	}
	sort(p,p+n);
	reverse(p,p+n);
	memset(sub,-1,sizeof(sub));
	for(ll i=0;i<n-1;i++)
	{
		ll de=p[i].first;
		ll x=p[i].second;
		sub[x]=n-sz[x]*2;
//		cout<<x+1<<'-'<<de<<'-'<<sub[x]<<'-'<<sz[i]<<endl;
		if(sub[x]==0) over("-1");
		if(m.find(de-sub[x])==m.end()) over("-1");
		ll par=m[de-sub[x]];
		sz[par]+=sz[x];
		dp[par]+=dp[x];
		res.push_back(mp(x,par));
	}
	for(int i=0;i<n-1;i++)
	{
		vec[res[i].first].push_back(res[i].second);
		vec[res[i].second].push_back(res[i].first);
	}
	dfs(p[n-1].second);
	go(p[n-1].second);
//	cout<<dp[p[n-1].second]<<endl;
	if(dp[p[n-1].second]!=p[n-1].first) over("-1");
	for(ll i=0;i<n-1;i++)
	{
		cout<<res[i].first+1<<' '<<res[i].second+1<<endl;
	}
	return 0;
}