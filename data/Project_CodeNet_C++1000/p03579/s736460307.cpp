#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> color;

bool dfs(const Graph &G, int v, int c){
  color[v] = c;
  for(auto next_v : G[v]){
    if(color[next_v] == c) return false;
    if(color[next_v] == 0 && !dfs(G, next_v, -c)) return false;
  }
  return true;
}

int main(){
  long long n, m;
  cin >> n >> m;
  Graph G(n);
  int a, b;
  for(int i=0; i<m; ++i){
    cin >> a >> b;
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
  }

  color.assign(n, 0);
  bool flag = true;
  for(int i=0; i<n; ++i){
    if(color[i] == 0){
      if(!dfs(G, i, 1)) flag = false;
    }
  }

  if(flag){
    long long white = 0;
    long long black = 0;
    for(int i=0; i<n; ++i){
      if(color[i] == 1) white++;
      else if(color[i] == -1) black++;
    }
    cout << white*black - m << "\n";
  }
  else{
    cout << n*(n-1)/2 - m << "\n"; //任意の２点間の距離を奇数にできる
  }
}