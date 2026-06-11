#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> P;

const int N = 2e5 + 10;

vector <int> G[N];
queue <P> q;
int dist[N];
int far;

int bfs(int s){
	int u, v, d, maxx;
	memset(dist, -1, sizeof(dist));
	q.push({s, 0});
	far = s;
	maxx = dist[s] = 0;
	while (!q.empty()){
		u = q.front().first; d = q.front().second; q.pop();
		if (d > maxx){
			far = u;
			maxx = d;
		}
		for (int i = 0; i < G[u].size(); i++){
			v = G[u][i];
			if (~dist[v]) continue;
			q.push({v, d + 1});
			dist[v] = d + 1;
		}
	}
	return maxx;
}

int main(){
	int n, u, v;
	scanf("%d",&n);
	for (int i = 1; i <= n - 1; i++){
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bfs(1);
	if (bfs(far) % 3 == 1) printf("Second\n");
	else printf("First\n");
	return 0;
}