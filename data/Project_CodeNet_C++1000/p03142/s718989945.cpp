#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

using Graph = vector<vector<int> >;

// トポロジカルソートする
void rec(int v, const Graph &G, vector<bool> &seen, vector<int> &order) {
    seen[v] = true;
    for (auto next : G[v]) {
        if (seen[next]) continue; // 既に訪問済みなら探索しない
        rec(next, G, seen, order);
    }
    order.push_back(v);
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

    //orderには葉から順に並んでいる
    vector<int> dummy(N);
    for (int ii = 0; ii < N; ++ii){
    	dummy[order[ii]] = ii;
    }

	vector <int> parent(N, -1);
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

	for (int ii = 0; ii < N; ++ii){
		cout << parent[ii] + 1 << endl;
	}

}
