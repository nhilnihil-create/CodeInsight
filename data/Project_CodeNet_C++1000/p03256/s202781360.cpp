#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(int)(a); i!=(int)(b); i++)
#define RFOR(i, a, b) for(int i=(int)(a); i!=(int)(b); i--)
#define REP(i, n) FOR(i, 0, n)
using namespace std;
using ll = long long;

constexpr int lim = 2*1e5;
int a[lim+1], b[lim+1];
int main(){
  int n, m; cin >> n >> m;
  string s; cin >> s;

  set<int> g[n];

  REP(i, m){
    int x, y; cin >> x >> y;
    x--; y--;
    g[x].insert(y);
    g[y].insert(x);
  }

  set<int> q;
  REP(i, n){
    for(auto x: g[i]){
      if(s[x] == 'A') a[i]++;
      else b[i]++;
    }
    if(a[i] == 0 || b[i] == 0) q.insert(i);
  }
  
  int cnt = 0;
  while(q.size()){
    int v = *q.begin(); 
    q.erase(q.begin());
    cnt++;
    for(auto x: g[v]){
      if(x == v) continue;

      g[x].erase(v);
      if(s[v] == 'A') a[x]--;
      else b[x]--;

      if(a[x] == 0 || b[x] == 0) q.insert(x);
    }
  }

  if(cnt == n) cout << "No" << endl;
  else cout << "Yes" << endl;

  return 0;
}
