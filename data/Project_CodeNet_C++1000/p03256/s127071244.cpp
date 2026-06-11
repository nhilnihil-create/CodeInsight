#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;
#define TOSTRING(x) #x
#define SZ(x) (int)(x).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPR(i,n) for(int i=(n)-1;i>=0;i--)
#define ALL(s) (s).begin(), (s).end()
#define so(V) sort(ALL(V))
#define rev(V) reverse(ALL(V))
#define uni(v) v.erase( unique(ALL(v)) , v.end());
#define PAU system("pause")

typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = (1 << 28);
const double PI = acos(-1);

struct Edge {
public:
	int from, to, id;
	Edge() {}
	Edge(int _from, int _to, int _id) {
		from = _from;
		to = _to;
		id = _id;
	}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int N, M;
string S;

vvi outdeg;
vb visited;
queue<int> Q;

void bfs(Graph G) {
	while (!Q.empty()) {
		int u = Q.front	(); Q.pop();
		for (Edge e : G[u]) {
			outdeg[e.to][e.id]--;
			if ((!visited[e.to]) && outdeg[e.to][e.id] == 0) {
				Q.push(e.to);
				visited[e.to] = true;
			}
		}
	}
}


bool TSort(Graph G) {
	visited = vb(N,false);
	REP(i, N) {
		if (outdeg[i][0]*outdeg[i][1] == 0) {
			Q.push(i);
			visited[i] = true;
		}
	}
	bfs(G);

	REP(i, N) {
		if (!visited[i])return true;
	}
	return false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	cin >> S;
	Graph G(N);
	outdeg = vvi(N, vi(2, 0)); //0 => A ,1 => B
	REP(i, M) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (S[b] == 'A') {
			outdeg[a][0]++;
			G[b].push_back(Edge(b, a, 0));
		}
		else {
			outdeg[a][1]++;
			G[b].push_back(Edge(b, a, 1));
		}
		if (S[a] == 'A') {
			outdeg[b][0]++;
			G[a].push_back(Edge(a, b, 0));
		}
		else {
			outdeg[b][1]++;
			G[a].push_back(Edge(a, b, 1));
		}
	}

	if (TSort(G))cout << "Yes" << endl;
	else cout << "No" << endl;
	PAU;
	return 0;
}
