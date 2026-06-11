#include <bits/stdc++.h>
using namespace std;

struct node{  
  int to;
  int dis;
};

int N;
int NMAX = 100001;
vector<vector<node>> tree(NMAX);
vector<int> color(NMAX, -1);
vector<bool> check(NMAX);

void dfs(int k, int distance){  
  check[k] = true;
  if(distance % 2 == 0) color[k] = 0;
  else color[k] = 1;
  for(auto n: tree[k]){  
    int to = n.to;
    if(!check[to]){  
      dfs(to, distance + n.dis); 
    }
  } 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  cin >> N;
  for(int i = 0; i < N-1; i++){  
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    node n1 = {v, w};
    node n2 = {u, w};
    tree[u].push_back(n1);
    tree[v].push_back(n2);
  }
  dfs(0, 0);
  for(int i = 0; i < N; i++) cout << color[i] <<endl;
}
