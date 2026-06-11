#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<tuple>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
int K;
vpint adj[100001];
int d[100001],color[100001],p[100001];
void dijkstra(int s){
	priority_queue<pint> PQ;
	rep(i,K){
		d[i]=INF;
		color[i]=0;
	}
	d[s]=0;
	color[s]=1;
	PQ.push(mp(0,s));
	while(!PQ.empty()){
		pint f=PQ.top();
		PQ.pop();
		int u=f.second;
		color[u]=2;
		if(d[u]< -f.first) continue;
		rep(j,adj[u].size()){
			int v=adj[u][j].first;
			if(color[v]==2) continue;
			if(d[v]>d[u]+adj[u][j].second){
				d[v]=d[u]+adj[u][j].second;
				PQ.push(mp(-d[v],v));
				color[v]=1;
			}
		}
	}
}
int main(){
	scan(K);
	rep(i,K){
		if(i%10!=9) adj[i].push_back(mp((i+1)%K,1));
	}
	rep(i,K){
		adj[i].push_back(mp(i*10%K,0));
	}
	dijkstra(1);
	prin(d[0]+1);
	return 0;
}
