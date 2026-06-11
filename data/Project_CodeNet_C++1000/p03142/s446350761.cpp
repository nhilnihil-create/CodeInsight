#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int> >; // グラフ

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
    int N, M; cin >> N >> M; // 頂点数と枝数
    Graph G(N); // 頂点数 N のグラフ
    for (int i = 0; i < M+N-1; ++i) {
        int a, b;
        cin >> a >> b; // ノード a からノード b へと有向辺を張る
        a--;b--;
        G[a].push_back(b);
    }

    // 探索
    vector<bool> seen(N, 0); // 初期状態では全ノードが未訪問
    vector<int> order; // トポロジカルソート順
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue; // 既に訪問済みなら探索しない
        rec(v, G, seen, order);
    }
    reverse(order.begin(), order.end()); // 逆順に
    map<int,int>b;
    for (auto v : order){
        for(auto x : G[v]){
            b[x]=v+1;
        }
    }
    for(int i=0;i<N;++i)cout<<b[i]<<endl;
}