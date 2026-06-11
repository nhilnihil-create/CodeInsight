#include <iostream> // cin, cout, cerr, clog
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota, accumulate, inner_product
#include <cstdio> // printf, scanf
#include <climits> // INT_MIN, LLONG_MIN
#include <cmath> // long, trig, pow
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <stack> // stack
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <unordered_map> // hashed by keys
#include <unordered_set> // hashed by keys
#include <iomanip> // cout<<setprecision(n)
#include <functional> // std::function<void(int)>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ENDL '\n'
#define print(i) std::cout << (i) << '\n'

#define int long long // at least int64 > 9*10^18
#define all(v) (v).begin(), (v).end()
/* libraries */

struct Edge
{
	int a,b;
	Edge(int a, int b) : a(a),b(b) {}
};

signed main() {
	int n,m;
	std::cin >> n >> m;
	std::vector<std::vector<int> > from(n+1,std::vector<int>());
	std::vector<std::vector<int> > to(n+1,std::vector<int>());
	std::vector<int> dist(n+1,0);
	std::vector<Edge> edges;
	rep(i,n-1+m) {
		int a,b;
		std::cin >> a >> b;
		from[a].emplace_back(b);
		to[b].emplace_back(a);
		edges.emplace_back(a,b);
	}
	int root = 0;
	for(int i=1;i<=n;i++) {
		if(to[i].size()==0) {
			root = i;
			break;
		}
	}

	// dfs backwards
	std::function<int(int)> dfs = [&] (int i) -> int {
		if(i==root) return 0;
		if(dist[i]!=0) return dist[i];
		int max = 0;
		for(int a:to[i]) {
			max = std::max(dfs(a)+1,max);
		}
		return dist[i] = max;
	};

	for(int i=1;i<=n;i++) {
		dfs(i);
	}

	std::vector<int> parent(n+1,0);
	for(Edge e:edges) {
		if(dist[e.b]-dist[e.a]==1) parent[e.b] = e.a;
	}

	for(int i=1;i<=n;i++) print(parent[i]);


	return 0;
}
