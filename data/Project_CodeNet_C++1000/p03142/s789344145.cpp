#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define F first 
#define S second
#define int long long
#define endl "\n"

using namespace std;

/*
		TOUGH TIMES DON'T LAST TOUGH PEOPLE DO :)
		COURAGE IS ONE STEP AHEAD OF FEAR :)
*/

const int nax=3e5+5;
vector<int>adj[nax];
const int mod=1e9+7;
const int inf=1e18+7;

int n,m;
int deg[nax];
int P[nax];
int R[nax];

// void dfs(int cur, int p){
// 	if(R[cur] <= R[p]){
// 		R[cur] = R[p]+1;
// 		P[cur] = p;
// 	}
// 	for(auto u:adj[cur]){
// 		if(u!=p)
// 		dfs(u,cur);
// 	}
// }

signed main(){
	fast;
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt","r",stdin);
// 	freopen("output.txt","w",stdout);
// #endif
	cin>>n>>m;
	for(int i=1;i<n+m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		deg[b]++;
	}
	int node = 0;
	for(int i=1;i<=n;i++){
		if(deg[i] == 0){
			node = i;
			P[node]= 0;
			break;
		}
	}
	R[node] = 0;
	queue<int>q;
	q.push(node);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i = 0;i<adj[cur].size();i++){
			deg[adj[cur][i]]--;
			if(deg[adj[cur][i]] == 0){
				P[adj[cur][i]] = cur;
				q.push(adj[cur][i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<P[i]<<endl;
	}
	return 0;
}