#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(x, y) x = max(x, y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int n; cin >> n;
  vector<vector<int>> e(n);
  rep(i, n - 1){
    int a, b; cin >> a >> b;
    a--; b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  vector<int> c(n);
  rep(i, n) cin >> c[i];
  sort(c.begin(), c.end());
  reverse(c.begin(), c.end());

  int cid = 0;
  vector<int> t(n, -1);
  t[0] = c[cid];
  cid++;
  queue<int> q;
  q.push(0);
  int ans = 0;
  while(q.size() > 0){
    int now = q.front(); q.pop();
    for(int next : e[now]){
      if(t[next] != -1) continue;
      q.push(next);
      t[next] = c[cid];
      ans += c[cid];
      cid++;
    }
  }
  cout << ans << endl;
  rep(i, n){
    cout << t[i] << " ";
  }
  return 0;
}
