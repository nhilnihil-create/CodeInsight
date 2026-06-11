#include <bits/stdc++.h>
using namespace std;

using Edge = pair<int64_t,int64_t>;
using Graph = vector<vector<Edge>>;

int64_t N;
vector<int64_t> ans;
Graph G;

// vは今見ている頂点, pはvの親, cをvに塗る
void dfs(int64_t v, int64_t p, int64_t c ) {
    ans[v] = c;
    for ( auto u: G[v] ){
        int64_t nv = u.first;
        int64_t w = u.second;
        if ( nv == p ) continue;
        if ( w % 2 == 0 ){
            // 距離が偶数の場合
            dfs(nv,v,c);
        } else {
            // 距離が奇数の場合
            dfs(nv,v,(c+1)%2);
        }
    }
}

int main() {
    cin >> N;
    vector<int64_t> u(N-1),v(N-1),w(N-1);
    for ( int64_t i = 0; i < N-1; ++i){
        int64_t U,V;
        cin >> U >> V >> w.at(i);
        u.at(i) = U - 1;
        v.at(i) = V - 1;
    }
    
    G.assign(N,vector<Edge>());
    for ( int64_t i = 0; i < N-1; ++i){
        G[u.at(i)].push_back(Edge(v.at(i),w.at(i)));
        G[v.at(i)].push_back(Edge(u.at(i),w.at(i)));
    }
    
    for ( int64_t i = 0; i < N; ++i ){
        for ( auto e: G[i] ){
            int64_t j = e.first;
            int64_t k = e.second;
            //cout << i << " " << j << " " << k << endl;
        }
    }
    
    ans.assign(N,-1);
    
    dfs(0,-1,0);
    
    for ( auto c: ans){
        cout << c << endl;
    }
    
    
    return 0;
}
