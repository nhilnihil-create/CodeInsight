
#if 1
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <set>
#include <map>
#include <numeric>
#include <cassert>
#include <iomanip>

using namespace std;
#define int long long
#define uint unsigned long long
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr int INF = 1145141919810893;

//
struct Edge {
	int next;
	int w = 1;
};
template<class T>
struct Vertex {
	std::vector<Edge>edges;
	T val = {};
};
template<class T>
struct Graph {
	std::vector<Vertex<T>> vertex;
public:
	Graph(size_t n = 0) :vertex(n) {
	}
	void setArray(int u, int v, int w = 1) {
		vertex[u].edges.push_back(Edge{ v ,w });
	}
	void setConnect(int u, int v, int w = 1) {
		setArray(u, v, w);
		setArray(v, u, w);
	}
	T& val(int u) {
		return vertex[u].val;
	}
	void dfsImpl(int pos, int prev, std::function<void(int now, int next, int w)> func) {
		for (auto& e : vertex[pos].edges) {
			if (e.next == prev) continue;
			func(pos, e.next, e.w);
			dfsImpl(e.next, pos, func);
		}
	}
	void dfs(int pos, std::function<void(int now, int next, int w)> func) {
		dfsImpl(pos, -1, func);
	}
	//graph.dfs(0, [](Vertex<int>& now, Vertex<int>& next, int w) {});
	int radius() {
		if (vertex.size() <= 1)return 0;
		int farestID = -1;
		int far = -1;
		val(0) = 0;
		dfs(0, [&](int now, int next, int w) {
			val(next) = 1 + val(now);
			if (val(next) > far) {
				far = val(next);
				farestID = next;
			}
			});
		far = -1;
		val(farestID) = 0;
		dfs(farestID, [&](int now, int next, int w) {
			val(next) = 1 + val(now);
			if (val(next) > far) {
				far = val(next);
				farestID = next;
			}
			});
		return far;
	}
};




#define LOADVEC(type,name,N) std::vector<type>name(N); \
for (int nnn = 0; nnn < N; ++nnn) { \
	cin >> name[nnn]; \
}

#define LOADVEC2(type,name0,name1,N) std::vector<type>name0(N),name1(N); \
for (int nnn = 0; nnn < N; ++nnn) { \
	cin >> name0[nnn];cin >> name1[nnn]; \
}

#define LOADVEC3(type,name0,name1,name2,N) std::vector<type>name0(N),name1(N),name2(N); \
for (int nnn = 0; nnn < N; ++nnn) { \
	cin >> name0[nnn];cin >> name1[nnn];cin >> name2[nnn]; \
}

#define LOAD(type,name) type name; \
cin >> name;


void proc();

signed main() {
	ios::sync_with_stdio(false);
	proc();
	return 0;
}

/*
--------------------------------------------------------
--------------------------------------------------------
---------------    template      ----------------------
--------------------------------------------------------
--------------------------------------------------------
*/


void proc() {
	LOAD(int, N);
	Graph<int> graph(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		graph.setConnect(a - 1, b - 1);
	}
	if (graph.radius() % 3 == 1) {
		cout << "Second" << endl;
	}
	else {
		cout << "First" << endl;
	}
}


#endif

