#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);

  vector<vector<int>> d(h, vector<int>(w, -1));
  d.at(0).at(0) = 1;
  queue<pair<int, int>> q;
  q.push({0, 0});
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  while(!q.empty()){
    auto now = q.front(); q.pop();
    rep(k, 4){
      int ni = now.first + di[k], nj = now.second + dj[k];
      if(nj < 0 || w <= nj || ni < 0 || h <= ni) continue;
      if(s.at(ni).at(nj) == '#' || d.at(ni).at(nj) != -1) continue;
      d.at(ni).at(nj) = d.at(now.first).at(now.second) + 1;
      q.push({ni, nj});
    }
  }
  int wc = 0;
  rep(i, h)rep(j, w)if(s.at(i).at(j) == '.') wc++;
  cerr << d.at(h-1).at(w-1) << " " << wc << endl;
  if(d.at(h-1).at(w-1) == -1){
    cout << -1 << endl;
    return 0;
  }
  int ans = wc - d.at(h-1).at(w-1);
  cout << ans << endl;
  return 0;
}