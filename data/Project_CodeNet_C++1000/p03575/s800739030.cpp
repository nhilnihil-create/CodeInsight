#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &p, int x){
  if(p[x] == x)  return x;
  return p[x] = find(p, p[x]);
}
void unite(vector<int> &p, int x, int y){
  x = find(p, x), y = find(p, y);
  p[x] = y;
}
bool same(vector<int> &p, int x, int y){
  x = find(p, x);
  y = find(p, y);
  return (x == y);
}

int main(){
  int n, m;  cin >> n >> m;
  vector<int> p(n+1);
  vector<pair<int, int>> e(m);
  for(int i=0; i<m; i++)  cin >> e[i].first >> e[i].second;

  int ans = 0;
  for(int i=0; i<m; i++){
    for(int i=1; i<=n; i++)  p[i] = i;
    for(int j=0; j<m; j++){
      if(j == i)  continue;
      unite(p, e[j].first, e[j].second);
    }
    bool hasi = false;
    
    for(int j=2; j<=n; j++)
      if(!same(p, 1, j))  hasi = true;
    if(hasi)  ans++;
  }
  cout << ans << endl;
  return 0;
}
