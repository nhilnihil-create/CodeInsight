#include <bits/stdc++.h>
 
using namespace std;
 
#define forsn(i, s, n) for(int i=s;i<int(n);i++)
#define forn(i, n) forsn(i, 0, n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
 
typedef long long tint;
 
const int INF = 1e6;
const int MOD = 1e9+7;

vector<int> adj[201];
bool visited[201];
int match[201];

bool dfs(int node){
	if(visited[node]) return 0;
	visited[node] = 1;
	for(auto u : adj[node]){
		if(match[u] == -1 || dfs(match[u])){
			match[node] = u;
			match[u] = node;
			return 1;
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n; cin >>  n;
	vector<pair<int,int>> red (n);
	vector<pair<int,int>> blue (n);
	forn(i, n) cin >> red[i].x >> red[i].y;
	forn(i, n) cin >> blue[i].x >> blue[i].y;
	forn(i, n){
		forn(j, n){
			if(red[i].x < blue[j].x && red[i].y < blue[j].y){
				adj[i].push_back(100+j);
				adj[100+j].push_back(i);
			}
		}
	}
	forn(i, 202){
		match[i] = -1;
	}
	while(1){
		memset(visited, 0, sizeof visited);
		bool cont = 0;
		forn(i, n){
			if(match[i]==-1)cont|=dfs(i);
		}
		if(cont==0)break;
	}
	int ret = 0;
	forn(i, 100){
		if(match[i] != -1) ret++;
	}
	cout << ret << "\n";
}
