#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> P;
int depth[100005];
int ans[100005];
vector<int> pa[100005];


int dfs(int v) {
  if(depth[v] != -1) return depth[v];
  
  vector<P> tmp;

  for(int i = 0; i < pa[v].size(); i++) {
    tmp.push_back(P(dfs(pa[v][i]),pa[v][i]));   
  }
  sort(tmp.begin(),tmp.end());
  ans[v] = tmp.back().second;
  
  return depth[v] = tmp.back().first + 1;
}
  
  

int main() {
  int n,m;
  cin >> n >> m;

  for(int i = 0; i < n+m-1; i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    pa[b].push_back(a);
  }
  for(int i = 0; i < n; i++) depth[i] = -1;

  for(int i = 0; i < n; i++) {
    if(pa[i].size() == 0) {
      ans[i] = -1;
      depth[i] = 0;
    }
    else if(pa[i].size() == 1) {
      if(depth[pa[i][0]] != -1) {
	depth[i] = depth[pa[i][0]] + 1;
	ans[i] = pa[i][0];
      }
    }
  }

  for(int i = 0; i < n; i++) {
    if(depth[i] == -1) {
      dfs(i);
    }
  }

  for(int i = 0; i < n; i++) cout << ans[i] + 1 << endl;
}
