#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define INFLL 0x3f3f3f3f3f3f3f3fLL 
#define EPS 10e-9
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define st first
#define nd second
#define sz(v) int(v.size())
#define all(X) (X).begin(), (X).end()
#define FOR(I, A, B) for(int I = A; I < B; I++)
#define RFOR(I, A, B) for(int I = A; I >= B; I--)

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

int n;
vi adjList[200100];
int dist[200100];
bool vis[200100];

void dfs(int u){
	vis[u] = true;
	for(int v : adjList[u]){
		if(vis[v]) continue;
		dist[v] = dist[u] + 1;
		dfs(v);
	}
}

int diameter(){
	dfs(1);
	int furthestNode = 0;
	FOR(i,1,n+1){
		if(dist[i] > dist[furthestNode]){
			furthestNode = i;
		}
	}
	memset(dist, 0, sizeof dist);
	memset(vis, false, sizeof vis);
	dfs(furthestNode);
	int ans = 0;
	FOR(i,1,n+1){
		ans = max(ans, dist[i]);
	}
	return ans;
}

int main(){
	cin >> n;
	FOR(i,0,n-1){
		int a, b;
		scanf("%d%d", &a, &b);
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	int d = diameter();
	printf("%s\n", (d-1)%3 ? "First" : "Second");
	return 0;
}