#include <bits/stdc++.h>
#define int long long
#define INF 1000000000007
using namespace std;

int n,d[200010],sz[200010],dp[200010],minv,pos;
map<int,int> mp;
vector<pair<int,int> > res;
vector<int> v[200010];

inline void dfs(int u,int pr)
{
	for(int i=0;i<v[u].size();i++) if(v[u][i]!=pr){
		dfs(v[u][i],u);
		dp[u]+=dp[v[u][i]]+sz[v[u][i]];
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>d[i];mp[d[i]]=i;}
	minv=INF;
	for(int i=1;i<=n;i++){
		if(d[i]<minv){
			minv=d[i];
			pos=i;
		}
	}
	for(int i=1;i<=n;i++){sz[i]=1;}
  	map<int,int>::iterator it=mp.end();
  	it--;
	for(;it!=mp.begin();it--){
		int num=it->first,loc=it->second;
		if(loc==pos) continue;
		if(sz[loc]*2>=n){
			cout<<-1<<endl;
			return 0;
		}
		int cur=num-n+2*sz[loc];
		if(!mp.count(cur)){
			cout<<-1<<endl;
			return 0;
		}
		int par=mp[cur];
		res.push_back(make_pair(par,loc));
		sz[par]+=sz[loc];
	}
	for(int i=0;i<res.size();i++){
		v[res[i].first].push_back(res[i].second);
		v[res[i].second].push_back(res[i].first);
	}
	for(int i=1;i<=n;i++) dp[i]=0;
	dfs(pos,-1);
	if(dp[pos]!=minv){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<res.size();i++){
		cout<<res[i].first<<" "<<res[i].second<<endl;
	}
	return 0;
}