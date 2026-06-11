#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
template<typename T1,typename T2> inline bool chmax(T1& a,T2 b)
{if (a < b) {a = b; return true;} return false;}
template<typename T1,typename T2> inline bool chmin(T1& a,T2 b)
{if (a > b) {a = b; return true;} return false;}

int N;
Graph G;

int Tree_Diameter(const Graph &G){
    int MAX_D = -1, node = 0;
    vector<bool> seen(G.size(), false);
    stack<pair<int, int>> sta; sta.emplace(0, 0);
    while(!sta.empty()){
        int dep, v; tie(v, dep) = sta.top(); sta.pop();
        seen[v] = true;
        if (chmax(MAX_D, dep)) node = v;
        for (auto e : G[v]) {
            if (seen[e]) continue;
            sta.emplace(e, dep + 1);
        }
    }
    MAX_D = -1; seen.assign(G.size(), false);
    sta.emplace(node, 0);
    while(!sta.empty()){
        int dep, v; tie(v, dep) = sta.top(); sta.pop();
        seen[v] = true; chmax(MAX_D, dep);
        for (auto e : G[v]) {
            if (seen[e]) continue;
            sta.emplace(e, dep + 1);
        }
    }
    
    return MAX_D;
}

int main(){
    int N; cin >> N;
    Graph G(N, vector<int>());
    for (int i = 1; i < N; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].emplace_back(b); G[b].emplace_back(a);
    }
  int R = Tree_Diameter(G);
  if (R % 3 == 1) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }
  return 0;
}