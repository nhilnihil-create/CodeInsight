#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pl = pair<int, ll>;
const int MAX_K = 100005;
const ll LINF = 1LL << 60;
using P = pair<int, int>;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)

class edge {
public:
	long long cost; int to;
	edge(long long cost, int to)
		:cost(cost), to(to) {}
};
vector<edge> e[MAX_K];
long long d1[MAX_K];

void dijkstra(int start, vector<edge> graph[], long long d[]) {
	priority_queue<Pl, vector<Pl>, greater<Pl>> que;
	fill(d, d + MAX_K, LINF);
	d[start] = 0LL;
	que.push(Pl(0LL, start));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second; //行き先
		if (d[v] < p.first)  continue;
		rep(i, graph[v].size()) {
			edge e = graph[v][i];
			if (d[v] + e.cost < d[e.to]) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
	return;
}

int main() {
	int K;
	cin >> K;
	for (int i = 0;i<K;++i) {
		e[i].push_back(edge(1LL, (i + 1) % K));
	}	
	for (int i = 1; i < K; ++i) {
		e[i].push_back(edge(0LL, (i * 10) % K));
	}
	dijkstra(1, e, d1);
	cout << d1[0] + 1LL << endl;
	return 0;
}