#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define mt make_tuple
#define pb push_back


string s;
int n, m;
set<int> c[200005][2];
bool deleted[200005];
vector<int> adj[200005];
int32_t main(){
	cin>>n>>m>>s;
	for(int i = 0 ; i < m ; i ++){
		int x , y;
		cin>>x>>y;
		x-- , y--;
		adj[x].pb(y);
		adj[y].pb(x);
		c[x][s[y] - 'A'].insert(y);
		c[y][s[x] - 'A'].insert(x);
	}
	queue<int> q;
	for(int i = 0 ; i < n; i ++){
		if(c[i][0].size() > 0 && c[i][1].size() > 0){
			continue;
		}
		q.push(i);
	}
	bool can = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		deleted[u] = true;
		for(auto p : adj[u]){
			if(!deleted[p]){
				c[p][s[u] - 'A'].erase(u);
				if(c[p][0].size() > 0 && c[p][1].size() > 0){
					continue;
				}
				q.push(p);
			}
		}
	}
	can = false;
	for(int i = 0 ; i < n ; i++){
		if(!deleted[i]) can = true;
	}
	if(can) cout<<"Yes\n";
	else cout<<"No\n";
}