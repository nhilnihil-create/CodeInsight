#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

vi colour;
vvii adj;

void dfs(int node, int father, int c, int dist) {
	if(dist % 2 == 0) colour[node] = c;
	
	for(ii i : adj[node]) {
		if(i.ff != father) dfs(i.ff, node, c, dist + i.ss);
	}
}

void solve() {
	int n;
	cin >> n;
	
	colour.resize(n, 0);
	adj.resize(n);
	for(int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		adj[u].pub({v, w});
		adj[v].pub({u, w});
	}
	
	dfs(0, -1, 1, 0);
	for(int i = 0; i < n; i++) cout << colour[i] << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}