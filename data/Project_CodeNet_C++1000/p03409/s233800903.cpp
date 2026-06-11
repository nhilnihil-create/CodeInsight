#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const long long INF = (long long)1e18 + 100;

struct Edge
{
	int to;
	long long capacity;
};

struct Dinic
{
	struct Edge_Res
	{
		int to;
		long long capacity;
		int reverse_idx;
		bool is_backword;
	};

	int V;
	vector<vector<Edge_Res>> resnet;
	int s, t;
	long long max_flow;
	vector<int> level;
	vector<int> iter;

	Dinic(const vector<vector<Edge>> &g) : V(g.size()), resnet(V) {
		for (int i = 0; i < V; i++) {
			for (const Edge &e : g[i]) {
				resnet[i].push_back(Edge_Res{e.to, e.capacity, (int)resnet[e.to].size(), false});
				resnet[e.to].push_back(Edge_Res{i, 0, (int)resnet[i].size()-1, true});
			}
		}
	}

	Dinic(int V) : V(V), resnet(V) {}

	void add_edge(int from, int to, long long capacity) {
		resnet[from].push_back(Edge_Res{to, capacity, (int)resnet[to].size(), false});
		resnet[to].push_back(Edge_Res{from, 0, (int)resnet[from].size()-1, true});
	}

	bool is_s(int v) {
		return level[v] >= 0;
	}

	void calc(int s, int t) {
		this->s = s;
		this->t = t;
		max_flow = 0;
		while (true) {
			bfs(s);
			if (level[t] == -1) break;
			iter.assign(V, 0);
			while (true) {
				long long f = dfs(s, INF);
				if (f > 0) max_flow += f;
				else break;
			}
		}
		iter.clear();
		iter.shrink_to_fit();
	}

	void bfs(int s) {
		level.assign(V, -1);
		queue<int> q;
		q.push(s);
		level[s] = 0;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (Edge_Res &e : resnet[v]) {
				if (e.capacity <= 0) continue;
				if (level[e.to] != -1) continue;
				level[e.to] = level[v] + 1;
				q.push(e.to);
			}
		}
	}

	long long dfs(int v, long long flow) {
		if (v == t) return flow;
		for (int &i = iter[v]; i < resnet[v].size(); i++) {
			Edge_Res &e = resnet[v][i];
			if (e.capacity <= 0) continue;
			if (level[e.to] <= level[v]) continue;
			long long f = dfs(e.to, min(flow, e.capacity));
			if (f == 0) continue;
			e.capacity -= f;
			resnet[e.to][e.reverse_idx].capacity += f;
			return f;
		}
		return 0;
	}
};

struct MaximumBipartiteMatching
{
	int A, B;
	Dinic mf;
	int s, t;
	int num_of_matching;
	vector<pair<int, int>> matching;

	MaximumBipartiteMatching(int A, int B) : A(A), B(B), mf(A+B+2), s(A+B), t(A+B+1) {
		for (int i = 0; i < A; i++) {
			mf.add_edge(s, i, 1);
		}
		for (int i = 0; i < B; i++) {
			mf.add_edge(A+i, t, 1);
		}
	}

	void add_edge(int a, int b) {
		mf.add_edge(a, A+b, 1);
	}

	void calc() {
		mf.calc(s, t);
		num_of_matching = mf.max_flow;
		matching.reserve(num_of_matching);
		for (int i = 0; i < A; i++) {
			for (auto &e : mf.resnet[i]) {
				if (!e.is_backword && e.capacity == 0) {
					matching.emplace_back(i, e.to - A);
				}
			}
		}
	}
};

struct P
{
	int x, y;
	P(int x=0, int y=0) : x(x), y(y) {}
	friend ostream &operator<<(ostream &os, const P &a) {
		return os << '(' << a.x << ',' << a.y << ')';
	}
};

int main() {
	int n;
	cin >> n;
	vector<P> A(n), B(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i].x >> A[i].y;
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i].x >> B[i].y;
	}
	MaximumBipartiteMatching bm(n, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			P &a = A[i], &b = B[j];
			if (a.x < b.x && a.y < b.y) bm.add_edge(i, j);
		}
	}
	bm.calc();
	int ans = bm.num_of_matching;
	cout << ans << endl;
	return 0;
}