#include <cstdio>
#include <queue>
#include <vector>
#define pb push_back
using namespace std;

const int mxsz = 1e5 + 3;
int n, m;
vector<int> adj[mxsz];
int in[mxsz], d[mxsz], p[mxsz];

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0, a, b; i < n + m - 1; i++){
		scanf("%d %d", &a, &b);
		adj[a].pb(b);
		in[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) if (!in[i]) q.push(i);
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (int nx : adj[u]){
			d[nx] = max(d[nx], d[u] + 1);
			in[nx]--;
			if (!in[nx]) q.push(nx);
		}
	}
	for (int i = 1; i <= n; i++){
		for (int nx : adj[i]){
			if (d[nx] == d[i] + 1)
				p[nx] = i;
		}
	}
	for (int i = 1; i <= n; i++) printf("%d\n", p[i]);
	return 0;
}
