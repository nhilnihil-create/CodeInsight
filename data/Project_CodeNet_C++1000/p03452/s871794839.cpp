#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 100005;

int n, m;
vector<pi> gph[MAXN];
bool vis[MAXN], bad;
int col[MAXN];

void dfs(int x, int c){
	if(vis[x]){
		if(col[x] != c) bad = 1;
		return;
	}
	vis[x] = 1;
	col[x] = c;
	for(auto &i : gph[x]) dfs(i.second, c + i.first);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++){
		int s, e, x; scanf("%d %d %d",&s,&e,&x);
		gph[s].emplace_back(x, e);
		gph[e].emplace_back(-x, s);
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			dfs(i, 0);
		}
	}
	puts(!bad ? "Yes" : "No");
}
