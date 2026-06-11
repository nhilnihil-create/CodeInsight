#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

struct Edge {
	int to;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, long>;
/* Lowlink: グラフの関節点・橋を列挙する構造体
	作成: O(E+V)
	関節点の集合: vector<int> aps
	橋の集合: vector<P> bridges
*/
struct LowLink {
	const Graph &G;
	vector<int> used, ord, low;
	vector<int> aps;  // articulation points
	vector<P> bridges;
	LowLink(const Graph &G_) : G(G_) {
		used.assign(G.size(), 0);
		ord.assign(G.size(), 0);
		low.assign(G.size(), 0);
		int k = 0;
		for(int i = 0; i < (int)G.size(); i++) {
			if(!used[i]) k = dfs(i, k, -1);
		}
		sort(aps.begin(), aps.end());		   // 必要ならソートする
		sort(bridges.begin(), bridges.end());  // 必要ならソートする
	}
	int dfs(int id, int k, int par) {  // id:探索中の頂点, k:dfsで何番目に探索するか, par:idの親
		used[id] = true;
		ord[id] = k++;
		low[id] = ord[id];
		bool is_aps = false;
		int count = 0;	// 子の数
		for(auto &e : G[id]) {
			if(!used[e.to]) {
				count++;
				k = dfs(e.to, k, id);
				low[id] = min(low[id], low[e.to]);
				if(par != -1 && ord[id] <= low[e.to]) is_aps = true;
				if(ord[id] < low[e.to]) bridges.emplace_back(min(id, e.to), max(id, e.to));	 // 条件を満たすので橋
			} else if(e.to != par) {														 // eが後退辺の時
				low[id] = min(low[id], ord[e.to]);
			}
		}
		if(par == -1 && count >= 2) is_aps = true;
		if(is_aps) aps.push_back(id);
		return k;
	}
};

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	cout << A * B / 2 << "\n";
	return 0;
}