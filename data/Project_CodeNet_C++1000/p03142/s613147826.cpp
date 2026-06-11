#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

using Graph = vector<vector<int> >;
vector <int> depth;
vector <int> parent;

// トポロジカルソートする
void rec(int v, const Graph &G, vector<bool> &seen, vector<int> &order) {
    seen[v] = true;
    for (auto next : G[v]) {
        if (seen[next]) continue; // 既に訪問済みなら探索しない
        rec(next, G, seen, order);
    }
    order.push_back(v);
}

void dfs(const Graph& graph, int v, int p, int d) {
	if (parent[v] == -1){	//初訪問のとき
		parent[v] = p;
		depth[v] = d;
		for (auto nv : graph[v]){
			if (nv == p) continue;
			dfs(graph, nv, v, d + 1);
		}
	} else {	//初訪問でないとき
		int orgP = parent[v];
		int orgD = depth[v];
		bool cond1 = (orgP != p);
		bool cond2 = (orgD < d);

		if (cond1){
			if (cond2){
				parent[v] = p;
				depth[v] = d;
				for (auto nv : graph[v]){
					if (nv == p) continue;
					dfs(graph, nv, v, d + 1);
				}
			}
		} else {
			if (cond2){
				depth[v] = d;
				for (auto nv : graph[v]){
					if (nv == p) continue;
					dfs(graph, nv, v, d + 1);
				}				
			}
		}
	}
}

int main() {
    int N, M;
    cin >> N >> M;
    Graph G(N+M-1);
    Graph R(N+M-1);    
    for (int i = 0; i < N+M-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        R[b].push_back(a);
    }

    // トポロジカルソート
    vector<bool> seen(N, 0);
    vector<int> order;
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue;
        rec(v, G, seen, order);
    }
    // reverse(order.begin(), order.end());

    //orderには葉から順に並んでいる
    vector<int> dummy(N);
    for (int ii = 0; ii < N; ++ii){
    	dummy[order[ii]] = ii;
    }


	parent.assign(N, -1);
	for (int ii = 0; ii < order.size(); ++ii){
		int v = order[ii];
	    //nvの中でorderが最小のものを求める
	    int minV = 100100100;
	    for (auto nv : R[v]) {
	    	minV = min(minV, dummy[nv]);
	    }
	    if (minV != 100100100){
	    	parent[v] = order[minV];
	    }
	}

 //    //探索
 //    int root = order[0];
	// depth.assign(N, 0);
	// parent.assign(N, -1);
	// dfs(G, /*v=*/root, /*p=*/-1, /*d=*/0);

	for (int ii = 0; ii < N; ++ii){
		cout << parent[ii] + 1 << endl;
	}

}
