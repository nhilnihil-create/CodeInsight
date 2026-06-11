#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=100003;

int n,w[maxn],head[maxn],siz[maxn];
struct EDGE{
	int to,nxt;
}edge[maxn<<1];
void addedge(int u,int v){
	static int sz=0;edge[++sz].nxt=head[u];
	edge[sz].to=v;head[u]=sz;
}
ll d[maxn],dis[maxn],sum[maxn];
map<ll,int> mp;
vector<pii> v; 

void dfs(int u,int pre){
	int to;siz[u]=1;
	for(int i=head[u];i;i=edge[i].nxt){
		to=edge[i].to;
		if(to==pre) continue;
		dfs(to,u);
		sum[u]+=sum[to]+siz[to];
		siz[u]+=siz[to];
	}
}

void dfs1(int u,int pre){
	int to;
	for(int i=head[u];i;i=edge[i].nxt){
		to=edge[i].to;
		if(to==pre) continue;
		dis[to]=dis[u]+n-2*siz[to];
		dfs1(to,u);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&d[i]);
		mp[d[i]]=i;
		w[i]=1;
	}
	for(int i=1;i<n;++i){
		pair<ll,int> p=*mp.rbegin();
		int u=p.second;
		ll want=d[u]-n+2*w[u];
		if(mp.find(want)==mp.end()){
			puts("-1");
			return 0;
		}
		int to=mp[want];
		v.push_back(make_pair(u,to));
		addedge(u,to);
		addedge(to,u);
		w[to]+=w[u];
		mp.erase(--mp.end());
	}
	dfs(1,0);
	dis[1]=sum[1];
	dfs1(1,0);
	for(int i=1;i<=n;++i)
		if(dis[i]!=d[i]){
			puts("-1");
			return 0;
		}
	for(int i=0;i<v.size();++i)
		printf("%d %d\n",v[i].first,v[i].second);
	return 0;
}

