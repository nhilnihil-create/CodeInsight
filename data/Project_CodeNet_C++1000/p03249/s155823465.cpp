#include <bits/stdc++.h>
using namespace std;
int n,sz[100005],fa[100005];
long long d[100005],res;
map<long long,int> id;
priority_queue<pair<long long,int> > pq;
vector<int> e[100005];
vector<pair<int,int> > ans;
void dfs(int x,int d){
	res+=d;
	for(int i=0;i<e[x].size();i++) dfs(e[x][i],d+1);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		sz[i]=1;
		cin>>d[i];
		id[d[i]]=i;
		pq.push(make_pair(d[i],i));
	}
	while(pq.size()>1){
		int x=pq.top().second;pq.pop();
		id.erase(d[x]);
		if(!id.count(d[x]-(n-sz[x])+sz[x])){
			puts("-1");
			return 0;
		}
		fa[x]=id[d[x]-(n-sz[x])+sz[x]];
		sz[fa[x]]+=sz[x];
		e[fa[x]].push_back(x);
		ans.push_back(make_pair(fa[x],x));
	}
	int rt=pq.top().second;
	res=0;
	dfs(rt,0);
	if(res!=d[rt]){
		puts("-1"); 
	}
	else{
		for(int i=0;i<n-1;i++){
			printf("%d %d\n",ans[i].first,ans[i].second);
		}
	}
	return 0;
}