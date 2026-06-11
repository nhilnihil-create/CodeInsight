#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7,INF=mod*mod*3ll;;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

struct edge {ll to; ll cap; ll rev;} ;
vector<edge> G[205];
ll level[205];
ll iter[205];
void add_edge(ll from,ll to,ll cap){
	edge e;
	e.to=to, e.cap=cap, e.rev=G[to].size();
	G[from].push_back(e);
	e.to=from, e.cap=0, e.rev=G[from].size()-1;
	G[to].push_back(e);
}
void bfs(ll s){
	memset(level, -1, sizeof(level));
	queue<ll> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		ll v=que.front();
		que.pop();
		for(ll i=0; i<G[v].size(); i++){
			edge e=G[v][i];
			if(e.cap>0 && level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
ll dfs(ll v, ll t, ll f){
	if(v==t) return f;
	for(ll &i=iter[v]; i<G[v].size(); i++){
		edge &e=G[v][i];
		if(e.cap>0 && level[v]<level[e.to]){
			ll d=dfs(e.to, t, min(f, e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
ll max_flow(ll s, ll t){
	ll flow=0;
	while(1){
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter, 0, sizeof(iter));
		ll f;
		while((f=dfs(s, t, INF))>0){
			flow+=f;
		}
	}
}

ll N;
ll a[105],b[105],c[105],d[105];

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N;

rep(i,N) cin>>a[i]>>b[i];
rep(i,N) cin>>c[i]>>d[i];

//0~N-1 赤い点
//N~N+N-1 青い点
ll s=2*N,t=s+1;
rep(i,N) add_edge(s,i,1);
rep(i,N) add_edge(N+i,t,1);
rep(i,N){
	rep(j,N){
		if(a[i]<c[j]&&b[i]<d[j]) add_edge(i,j+N,1);
	}
}
cout<<max_flow(s,t)<<endl;

}
	
