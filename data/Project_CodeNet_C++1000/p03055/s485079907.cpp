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

int n;

vi dijkstra(int node, vvi &adj) {
	vi dist(n, inf);
	dist[node] = 0;
	priority_queue<ii> q;
	q.push({-dist[node], node});
	while(!q.empty()) {
		int node = q.top().ss; q.pop();
		for(int i : adj[node]) {
			if(dist[node] + 1 < dist[i]) {
				dist[i] = dist[node] + 1;
				q.push({-dist[i], i});
			}
		}
	}
	
	return dist;
}

void solve() {
	cin >> n;
	
	vvi adj(n);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		
		adj[u].pub(v);
		adj[v].pub(u);
	}
	
	vi dist1 = dijkstra(0, adj);
	int maxi = 0;
	for(int i = 0; i < n; i++) {
		if(dist1[maxi] < dist1[i]) maxi = i;
	}
	
	vi dist2 = dijkstra(maxi, adj);
	int mx = 0;
	for(int i = 0; i < n; i++) mx = max(mx, dist2[i]);
	
	int longest = mx;
	if(longest % 3 != 1) cout << "First" << endl;
	else cout << "Second" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}