#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<ll,ll> P;

const ll INF = 4e18;

int main(){
  int n, k;
  cin >> n >> k;
  
  vector<ll> x(n),y(n); 

  rep(i,n) {
    cin >> x[i] >> y[i];
  }
  vector<P> px,py;
  rep(i,n) {
    px.push_back({x[i],i});
    py.push_back({y[i],i});
  }
  sort(px.begin(),px.end());
  sort(py.begin(),py.end());

  vector<int> xc(n),yc(n);
  rep(i,n) {
    xc[px[i].second] = i;
    yc[py[i].second] = i;
  } 

  vector<vector<int> > cnt(n+1, vector<int>(n+1,0));
  rep(i,n) cnt[xc[i]+1][yc[i]+1]++;

  rep(i,n+1){
    rep(j,n+1){
      if (i > 0 && j > 0) cnt[i][j] += cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
    }
  } 
  ll res = INF;
  
  for (int xi = 0; xi < n; xi++) for (int xj = xi + 1; xj < n ; xj++) {
    for (int yi = 0; yi < n; yi++) for (int yj = yi + 1; yj < n; yj++) {
      int m = cnt[xj+1][yj+1] - cnt[xj+1][yi] - cnt[xi][yj+1] + cnt[xi][yi];
      if (m < k) continue;
      res = min(res, (px[xj].first-px[xi].first)*(py[yj].first-py[yi].first));
    }
  }
  
  cout << res << endl;
  return 0;
}