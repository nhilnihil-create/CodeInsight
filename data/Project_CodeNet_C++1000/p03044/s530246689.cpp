#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define endl '\n'
#define F first
#define S second
typedef pair<int, int> pii;
typedef long long ll;

const int MAX = 1e5+1;
vector<pii> g[MAX];
bool vis[MAX];
int color[MAX];

void dfs(pii u){
	vis[u.F] = 1;
	for(auto&x: g[u.F]){
		if(!vis[x.F]){
			if(x.S%2==0) color[x.F]=color[u.F];
			else color[x.F]=!color[u.F];
			dfs(x);
		}
	}
}

int main(){
	int n; cin>>n;
	int u, v, w;
	for(int i=0; i<n-1; i++){
		cin>>u>>v>>w;
		u--; v--;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dfs({0,0});
	for(int i=0; i<n; i++){
		cout<<color[i]<<endl;
	}
	return 0;   
}
