#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include <set>
#include <vector>
#include <queue>
using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)

static const double PI = 3.1415926535897932384626433;
static const ll LL_MAX = (ll)1 << 55;
///////////////////////////
////Prime Creator//////////
///////////////////////////
//bool Prime[100001] = {};
//void createPrime() {
//	ll n = 100001;
//	rep(i, 0, n) Prime[i] = true;
//	Prime[0] = false;
//	Prime[1] = false;
//	rep(i, 2, n) {
//		if (Prime[i]) {
//			rep(j, 2, n) {
//				if (j*i >= n)break;
//				Prime[j*i] = false;
//			}
//		}
//	}
//}
///////////////////////////
///////////////////////////

/////////////////////////
//Warshal Floyid/////////
/////////////////////////
//initialize
//
//static const ll LL_MAX = (ll)1 << 55;
//static const ll WF_MAX = 300;
//
//ll wf[WF_MAX][WF_MAX];
//void WarshalFloyid(int size) {
//	rep(k, 0, size)rep(i, 0, size)rep(j, 0, size)wf[i][j] = min(wf[i][j], wf[i][k] + wf[k][j]);
//}
//
////Bellmon ford
//// 隣接リストで使う辺を表す型
//struct Edge {
//	ll to, cost;  // 辺の接続先頂点, 辺の重み
//	Edge(ll to, ll cost) : to(to), cost(cost) {}  // コンストラクタ
//};
//typedef vector<vector<Edge> > AdjList;  // 隣接リストの型
//AdjList graph;  // グラフの辺を格納した構造体
//				// graph[v][i]は頂点vから出るi番目の辺Edge
//static const ll INF = (ll)1 << 55;
//vector<ll> dist; // 最短距離
//
//// 戻り値がtrueなら負の閉路を含む
//bool bellman_ford(int n, int s) { // nは頂点数、sは開始頂点
//	dist = vector<ll>(n, INF);
//	dist[s] = 0; // 開始点の距離は0
//	for (int i = 0; i < n; i++) {
//		for (int v = 0; v < n; v++) {
//			for (int k = 0; k < graph[v].size(); k++) {
//				Edge e = graph[v][k];
//				if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
//					dist[e.to] = dist[v] + e.cost;
//					if (i == n - 1) {
//						return true;
//					}
//				}
//			}
//		}
//	}
//	return false;
//}

//RMQ Segment Tree
//const int MAX_N = 1 << 17;
//int n, dat[2 * MAX_N - 1];
//
//void init(int n_) {
//	n = 1;
//	while (n < n_) n *= 2;
//	rep(i, 0, 2 * n - 1) dat[i] = INT_MAX;
//}
//
//void update(int k, int a) {
//	k += n - 1;
//	dat[k] = a;
//	while (k > 0) {
//		k = (k - 1) / 2;
//		dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
//	}
//}
//
//int query(int a, int b, int k, int l, int r) {
//	if (r <= a || b <= l) return INT_MAX;
//
//	if (a <= l && r <= b)return dat[k];
//	else {
//		int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
//		int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
//		return min(vl, vr);
//	}
//}
//
//int main() {
//	init(8);
//
//	update(0, 5);
//	update(1, 3);
//	update(2, 7);
//	update(3, 9);
//	update(4, 6);
//	update(5, 4);
//	update(6, 1);
//	update(7, 2);
//
//	cout << query(0, 6, 0, 0, n - 1) << endl;
//	return 0;
//}

//BIT Binary Index Tree
//int bit[MAX_N + 1], n;
//int sum(int i) {
//	int s = 0;
//	while (i > 0) {
//		s += bit[i];
//		i -= i;
//	}
//	return s;
//}
//void add(int i, int x) {
//	while (i <= n) {
//		bit[i] += x;
//		i += i & -i;
//	}
//}

//union find
//static const ll MAX_N = 200000;
//ll par[MAX_N];
//ll ran[MAX_N];
//
//void init(ll n) {
//	rep(i, 0, n) {
//		par[i] = i;
//		ran[i] = 0;
//	}
//}
//
//ll find(ll x) {
//	if (par[x] == x)  return x;
//	else return par[x] = find(par[x]);
//}
//
//void unite(ll x, ll y) {
//	x = find(x);
//	y = find(y);
//	if (x == y) return;
//
//	if (ran[x] < ran[y]) {
//		par[x] = y;
//	}
//	else {
//		par[y] = x;
//		if (ran[x] == ran[y]) ran[x]++;
//	}
//}
//bool same(ll x, ll y) {
//	return find(x) == find(y);
//}

//////////
//dijkstra
/////////
//ll N;
//static const ll MAX = 100001;
//static const ll INFTY = (ll)1 << 55;
//static const int WHITE = 1;
//static const int GRAY = 2;
//static const int BLACK = 3;
//vector<pair<int, int>>adj[MAX];
//ll d[MAX];
//ll pre[MAX];
//
//priority_queue<pair<int, int>>PQ;
//int color[MAX];
//ll n;
//void dijkstra(ll x) {
//	repe(i, 1, n) {
//		d[i] = INFTY;
//		color[i] = WHITE;
//	}
//
//	d[x] = 0;
//	PQ.push(make_pair(x, x));
//	color[x] = GRAY;
//	while (!PQ.empty()) {
//		pair<ll, ll> f = PQ.top(); PQ.pop();
//		ll u = f.second;
//		color[u] = BLACK;
//
//		if (d[u] < f.first * (-1))continue;
//
//		rep(j, 0, adj[u].size()) {
//			ll v = adj[u][j].first;
//			if (color[v] == BLACK)continue;
//			if (d[v] > d[u] + adj[u][j].second) {
//				d[v] = d[u] + adj[u][j].second;
//				pre[v] = u;
//				PQ.push(make_pair(d[v] * (-1), v));
//
//				color[v] = GRAY;
//			}
//		}
//	}
//}
//vector<ll> get_path(ll t) {
//	vector<ll> path;
//	for (; t != -1; t = pre[t])path.push_back(t);
//	reverse(path.begin(), path.end());
//	return path;
//}

//Topological Sort
//
//ll n, m, x, y, bit[20];
//ll dp[1 << 20];
//int main() {
//	cin >> n >> m; dp[0] = 1;
//	rep(i, 0, m) {
//		cin >> x >> y;
//		bit[y - 1] |= (1 << (x - 1));
//	}
//
//	rep(i, 1, 1 << n) {
//		rep(j, 0, n) {
//			if ((i & (i << j)) && (i | bit[j]) == i) {
//				dp[i] += dp[i - (i << j)];
//			}
//		}
//	}
//
//	return 0;
//}

int main() {
	ll n; cin >> n;
	ll a[51] = {};
	bool allPos = true;
	bool allNeg = true;
	ll maxV = 0;
	ll maxI = 0;
	ll minV = LL_MAX;
	ll minI = 0;
	repe(i, 1, n) {
		cin >> a[i];
		allPos &= (a[i] >= 0);
		allNeg &= (a[i] <= 0);
		if (maxV < a[i]) {
			maxV = max(maxV, a[i]);
			maxI = i;
		}
		if (minV > a[i]) {
			minV = min(minV, a[i]);
			minI = i;
		}
	}

	vector<pair<ll, ll>> v;
	if (!allPos && !allNeg) {
		if (maxV > abs(minV)) {
			repe(i, 1, n) {
				a[i] += maxV;
				v.push_back({ maxI, i });
			}
			allPos = true;
		}
		else {
			repe(i, 1, n) {
				a[i] -= minV;
				v.push_back({ minI, i });
			}
			allNeg = true;
		}
	}

	if (allPos) {
		rep(i, 1, n) {
			a[i + 1] += a[i];
			v.push_back({ i,i + 1 });
		}
	}
	else if (allNeg) {
		for (int i = n; i >= 2; i--) {
			a[i - 1] += a[i];
			v.push_back({ i,i - 1 });
		}
	}

	cout << v.size() << endl;
	for (vector<pair<ll, ll>>::iterator it = v.begin(); it != v.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}