/////////////////////////////////////////
////////// ^\/^ *_* :) :-D '~' \\\\\\\\\\
/////////////////////////////////////////
#include <bits/stdc++.h>
//#include <algorithm>
//#include <cstdio>
//#include <functional>
#include <iostream>
//#include <cfloat>
//#include <climits>
//#include <cstdlib>
//#include <cstring>
//#include <cmath>
//#include <map>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <string>
//#include <time.h>
//#include <vector>
//#include <random>
//#include <unordered_set>
//#include <complex>
//#include <string.h>
 
#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
 
using namespace std;
 
const LL MOD=1e9+7;
 
int n,m;
vector <pii> v[100010];
bool vis[100010];
int tot[100010];
 
void dfs(int pla,int all)
{
	if(vis[pla])
	{
		if(tot[pla]!=all)
		{
			puts("No");
			exit(0);
		}
		return;
	}
	vis[pla]=true;
	tot[pla]=all;
	rep(i,v[pla].size())
	{
		dfs(v[pla][i].fi,all+v[pla][i].se);
	}
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	rep(i,m)
	{
		int x,y,z;
		cin>>x>>y>>z;
		v[x].pb(mpr(y,z));
		v[y].pb(mpr(x,-z));
	}
	repn(i,n)
	{
		if(!vis[i])
		{
			memset(tot,0,sizeof(tot));
			dfs(i,0);
		}
	}
	puts("Yes");
	rt0;
}