#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int t[200005][2];
vector<int> g[200005];
bool used[200005];
queue<int> v;
int main() {
  int n,m;
  string s;
  cin >> n >> m >> s;
  for(int i = 0; i < m; i++) {
    int a,b;
    cin >> a >> b;
    a--,b--;
    g[a].push_back(b);
    g[b].push_back(a);
    if(s[a] == 'A') t[b][0]++;
    if(s[a] == 'B') t[b][1]++;
    if(s[b] == 'A') t[a][0]++;
    if(s[b] == 'B') t[a][1]++;
  }
  for(int i = 0; i < n; i++) {
    if(t[i][0] == 0 || t[i][1] == 0) {
      v.push(i);
      used[i] = true;
    }
  }
  int ans = v.size();
  // cout << ans << endl;
  while(!v.empty()) {
    int u = v.front();
    v.pop();
    int tmp = s[u] - 'A';
    for(int i = 0; i < g[u].size(); i++) {
      int e = g[u][i];
      t[e][tmp]--;
      if((t[e][0] == 0 || t[e][1] == 0) && !used[e]) {
	v.push(e);
	ans++;
	used[e] = true;
      }
    }
  }
  // cout << ans << endl;
  if(ans == n) cout << "No" << endl;
  else cout << "Yes" << endl;
}

  
  
