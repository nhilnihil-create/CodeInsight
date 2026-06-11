#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> g[100005];
int n,m;
int in[100005];
int depth[100005];
int ans[100005];

int main() {
  cin >> n >> m;
  for(int i = 0; i < n+m-1; i++) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    g[a].push_back(b);
    in[b]++;
  }

  vector<int> to;
  queue<int> q;
  for(int i = 0; i < n; i++) {
    if(in[i] == 0) {
      q.push(i);
      ans[i] = -1;
    }
  }
      
  while(!q.empty()) {
    int v = q.front();
    to.push_back(v);
    q.pop();
    for(int i = 0; i < g[v].size(); i++) {
      int u = g[v][i];
      in[u]--;
      if(in[u] == 0) {
	q.push(u);
      }
    }
  }


  for(int i = 0; i < to.size(); i++) {
    int v = to[i];
    for(int j = 0; j < g[v].size(); j++) {
      int u = g[v][j];
    
      depth[u] = depth[v] + 1;
      ans[u] = v;
    }
  }

  for(int i = 0; i < n; i++) cout << ans[i] + 1 << endl;
}
  
  
  
