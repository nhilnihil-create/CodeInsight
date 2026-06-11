/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment(" -Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
ll d[100005];
int sz[100005];
map<ll,int>mp;
vector<int>g[100005];
vector<pair<int,int> >ans;
ll sum=0;
void dfs(int x,int par,int dep){
	sum+=dep;
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i];
		if(to!=par)dfs(to,x,dep+1);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i];mp[d[i]]=i;sz[i]=1;
	}
	while(mp.size()>1){
		pair<ll,ll>p=*mp.rbegin();
		mp.erase(p.first);
		ll x=p.second,val=p.first;
		ll nxt_v=sz[x]*2+val-n;
		if(!mp.count(nxt_v)){
			puts("-1");
			return 0;
		}else{
			int y=mp[nxt_v];
			sz[y]+=sz[x];
			g[x].push_back(y);
			g[y].push_back(x);
			ans.push_back(make_pair(x,y));
		}
	}
	dfs(mp.begin()->second,-1,0);
	if(sum!=mp.begin()->first){
		puts("-1");
	}else{
		for(int i=0;i<ans.size();i++){
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
	}
	return 0;
}