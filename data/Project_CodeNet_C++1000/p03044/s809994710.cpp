#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
struct Edge {
	int idx;
	int len;
	Edge(int idx, int len) :
			idx(idx), len(len) {
	}
};
typedef struct Edge Edge;
typedef vector<Edge> ve;
typedef vector<ve> vve;

#define VLP(v,itr,_end) for(auto itr=v.begin(),_end=v.end();itr!=_end;++itr)
#define VCLP(v,itr,_end) for(auto itr=v.cbegin(),_end=v.cend();itr!=_end;++itr)

void dfs(vi &color, const vve &G, const int idx) {
	int c = color[idx], c_1 = (c ^ 1) & 1;
	VCLP(G[idx],itr,end) {
		if(color[itr->idx]!=-1){
			continue;
		}
		if (itr->len % 2 == 0) {
			color[itr->idx] = c;
		} else {
			color[itr->idx] = c_1;
		}
		dfs(color, G, itr->idx);
	}
}

int main() {
	int N;
	cin >> N;

	vve G(N);

	for (int i = 0; i < N - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u;
		--v;
		G[u].push_back(Edge(v, w));
		G[v].push_back(Edge(u, w));
	}

	vi color(N);
	VLP(color,itr,end) *itr=-1;
	color[0] = 0;

	dfs(color, G, 0);

	VCLP(color,itr,end) cout<<*itr<<endl;

	return 0;
}