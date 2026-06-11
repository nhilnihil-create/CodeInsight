#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,s,n)for(int i = s;i<n;i++)
#define repe(i,s,n)for(int i = s;i<=n;i++)
typedef long long ll;
static const ll MOD = 1e9 + 7;
static const ll INF = (ll)1 << 62;

static const int MAX = 100001;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
vector<pair<int, int>> adj[MAX];

ll pre[MAX];
ll p[MAX];
ll d[MAX];
ll color[MAX];
priority_queue<pair<int, int>>PQ;
ll n;
void dijkstra(int s) {
	rep(i, 0, n) {
		d[i] = INF;
		pre[i] = INF;
		color[i] = WHITE;
	}

	d[s] = 0;
	p[s] = -1;
	PQ.push(make_pair(s, s)); // ?reverse?
	color[s] = GRAY;

	while (!PQ.empty()) {
		pair<ll, ll> f = PQ.top(); PQ.pop();
		ll u = f.second;

		color[u] = BLACK;

		if (d[u] < f.first * (-1)) continue;

		rep(j, 0, adj[u].size()) {
			ll v = adj[u][j].first;
			if (color[v] == BLACK) continue;
			if (d[v] > d[u] + adj[u][j].second) {
				d[v] = d[u] + adj[u][j].second;
				PQ.push(make_pair(d[v] * (-1), v));
				p[v] = u;
				color[v] = GRAY;
			}
		}
	}
	//rep(i, 0, n) cout << i << " " << (d[i] == INF ? -1 : d[i]) << endl;
	//rep(i, 0, n) cout << i << " " << (p[i] == INF ? -1 : p[i]) << endl;
}

vector<ll> get_path(int t) {
	vector<ll> path;
	for (; t != -1; t = p[t])path.push_back(t);
	reverse(path.begin(), path.end());
	return path;
}

int main()
{
	cin >> n;
	rep(i, 0, n) {
		adj[i].push_back(make_pair((i + 1) % n, 1));
		adj[i].push_back(make_pair((i * 10) % n, 0));
	}

	dijkstra(1);

	cout << d[0] + 1 << endl;
	return 0;
}
