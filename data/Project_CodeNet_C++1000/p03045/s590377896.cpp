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

vvi adj;
vi color;

void dfs(int node, int c) {
	color[node] = c;
	for(int i : adj[node]) {
		if(!color[i]) dfs(i, c);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	adj.resize(n);
	for(int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		
		x--; y--;
		adj[x].pub(y);
		adj[y].pub(x);
	}	
	
	int c = 0;
	color.resize(n, 0);
	for(int i = 0; i < n; i++) {
		if(!color[i]) dfs(i, ++c);
	}
	
	cout << c << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}