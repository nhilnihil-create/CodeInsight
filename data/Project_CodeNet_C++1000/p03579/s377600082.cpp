#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> color;
vector<int64_t> cc = {0,0};//oと1の数を記録するvector
bool is_biparticle = true;

void dfs(Graph &G, int v , int cor = 0){
  color[v] = cor;
  cc[cor]++;
  for(auto next_v : G[v]){//ここが原因
    if(color[next_v] != -1){//隣接頂点が既に塗られてた場合は
      if(color[next_v] == cor) is_biparticle = false;//同色ならfalse
      else continue;//異色なら次の探査へ
    }

    else{//隣接頂点が未探査だった場合は
      dfs(G, next_v, 1-cor);//next_vの色を変えて探査する
    }
  }
}

int main(){
  int64_t n,m;cin >> n >> m;
  Graph G(n);
  for (size_t i = 0; i < m; i++) {
    int a,b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  color.assign(n,-1);
  dfs(G, 0);
  if(is_biparticle) std::cout << cc[0]*cc[1] - m << '\n';
  else std::cout << n*(n-1)/2 - m << '\n';
}
