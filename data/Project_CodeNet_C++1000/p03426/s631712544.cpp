#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
 
int main(){
  int h, w, d;
  cin >> h >> w >> d;
 
  vector<vector<int>> a(h, vector<int>(w));
  vector<P> ver(h*w); 
 
  rep(i,h) rep(j,w) {
    cin >> a[i][j];
    a[i][j]--;
    ver[a[i][j]] = make_pair(i, j);
  }
  vector<ll> cum(h*w+1, 0);
 
  for (int i = 0; i + d < h * w; i++) {
    int x = ver[i].first, y = ver[i].second;
    int nx = ver[i + d].first, ny = ver[i + d].second;
    int cost = abs(x - nx) + abs(y - ny);
    cum[i + d] = cum[i] + cost;
  }
  
  int q;
  cin >> q;
 
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << cum[r - 1] - cum[l - 1] << endl;
  }
  return 0;
} 