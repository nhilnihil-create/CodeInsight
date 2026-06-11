#include"bits/stdc++.h"
#define ll long long
#define inf 100005
using namespace  std;

vector<vector<ll>>g(inf);
vector<ll>indgree(inf);
vector<ll>dist(inf);
bool visted[inf];

void dfs(ll v){
	visted[v]=true;
	vector<ll>::iterator it;

	for(it=g[v].begin();it<g[v].end();it++){
		dist[*it]=max(dist[*it],dist[v]+1);
		indgree[*it]--;

		if(indgree[*it]==0){
			dfs(*it);
		}
	}
}

int main(){

	ll n,m,i,j,a,b;
	cin>>n>>m;

	for(i=0;i<m;i++){
		cin>>a>>b;
		g[a].push_back(b);
		indgree[b]++;
	}

	for(i=1;i<=n;i++){
		if(!visted[i] && indgree[i]==0){
			dfs(i);
		}
	}


	ll d=-1;

	for(i=1;i<=n;i++){
		if(d<dist[i]){
			d=dist[i];
		}
	}

	cout<<d<<endl;

	return 0;
}