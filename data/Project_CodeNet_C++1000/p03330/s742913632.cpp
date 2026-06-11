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
  int n, c;
  cin >> n >> c;
  vector<vector<int>> d(c, vector<int>(c));
  rep(i, c){
    rep(j, c){
      cin >> d.at(i).at(j);
    }
  }
  vector<vector<int>> vc(n, vector<int>(n));
  rep(i, n)rep(j, n){
    cin >> vc.at(i).at(j);
    vc.at(i).at(j)--;
  }

  vector<map<int, int>> mpv(3);
  rep(i, n){
    rep(j, n){
      mpv.at((i+j) % 3)[vc.at(i).at(j)]++;
    }
  }
  ll ans = 1e18;
  rep(i, c)rep(j, c)rep(k, c){
    if(i == j || j == k || i == k) continue;
    ll add = 0;
    for(auto p : mpv.at(0)){
      add += (ll)p.second * d.at(p.first).at(i);
    }
    for(auto p : mpv.at(1)){
      add += (ll)p.second * d.at(p.first).at(j);
    }
    for(auto p : mpv.at(2)){
      add += (ll)p.second * d.at(p.first).at(k);
    }
    // cerr << add << endl;
    ans = min(ans, add);
  }
  cout << ans << endl;
  return 0;
}