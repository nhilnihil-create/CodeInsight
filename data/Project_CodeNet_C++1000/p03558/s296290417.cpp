#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;(i)<(n);(i)++)
#define ll long long
//#define int long long

static const int MAX = 100005;
static const int INFTY = (1 << 20);

int K;
vector<pair<int, int>> adj[MAX];
int dist[MAX];
int ans;

void dijkstra(int s) {
	priority_queue<pair<int, int>> PQ;
	int color[MAX];

	REP(i, K) {
		color[i] = 0;
	}

	dist[s] = 0;
	PQ.push(make_pair(0, s));
	color[s] = 1;

	while (!PQ.empty()) {
		pair<int, int> f = PQ.top(); PQ.pop();
		int u = f.second;
		color[u] = 2;

		//最小値を取り出し，それが最短でなければ無視
		if (dist[u] < f.first*(-1)) continue;

		REP(j, adj[u].size()) {
			int v = adj[u][j].first;
			if (color[v] == 2) continue;
			if (dist[v] > dist[u] + adj[u][j].second) {
				dist[v] = dist[u] + adj[u][j].second;
				PQ.push(make_pair(dist[v] * (-1), v));
				color[v] = 1;
			}
		}
	}
}

signed main() {
	cin >> K;

	//1足す操作は桁和も+1
	for (int i = 0; i < K; i++) {
		adj[i].push_back(make_pair((i + 1) % K, 1));
	}
	//10倍する操作は桁和+0
	for (int i = 0; i < K; i++) {
		adj[i].push_back(make_pair((i * 10) % K, 0));
	}

	REP(i, K) dist[i] = INFTY;
	
	dijkstra(1);
	ans = dist[0] + 1;

	//REP(i, K) {
	//	cout << i << " " << (dist[i] == INFTY ? -1 : dist[i]) << endl;
	//}

	cout << ans << endl;

	return 0;
}