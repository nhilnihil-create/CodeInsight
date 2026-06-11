#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
int n,m,ans,cnt;
int low[60],vis[60];
vector<int>G[60];
void dfs(int x,int pr){
	vis[x]=low[x]=++cnt;
	for(auto to:G[x])if(to!=pr){
		if(vis[to])low[x]=min(low[x],vis[to]);
		else{
			dfs(to,x);
			low[x]=min(low[x],low[to]);
		}
	}
	if(low[x]==vis[x]&&pr!=-1)ans++;
}
int main(){
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		G[x].pb(y);
		G[y].pb(x);
	}
	dfs(1,-1);
	cout<<ans<<endl;
	return 0;
}
