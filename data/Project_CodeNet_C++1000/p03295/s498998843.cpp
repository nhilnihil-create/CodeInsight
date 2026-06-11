#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> vp(m);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    vp.at(i) = make_pair(b, a);
  }
  sort(vp.begin(), vp.end());
  int ans = 0, br = -1;
  rep(i, m){
    auto now = vp.at(i);
    // cerr << br << " " << vp.at(i).second << " " << vp.at(i).first << endl;
    if(br > now.second) continue;
    else{
      ans++;
      br = now.first;
    }
  }
  cout << ans << endl;
  return 0;
}