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
  int n, h;
  cin >> n >> h;
  vector<pair<int, int>> vp(n);
  rep(i, n){
    int a, b;
    cin >> a >> b;
    vp.at(i) = make_pair(a, b);
  }
  sort(vp.begin(), vp.end());
  auto mx = vp.back();
  vp.pop_back();
  sort(vp.begin(), vp.end(), [](const auto &l, const auto &r){
    return l.second > r.second;
  });
  int ans = 0, index = 0;
  while(h > 0){
    ans++;
    int ac = mx.first;
    if(h <= mx.second) h = 0;
    else{
      if(index != n-1 && ac < vp.at(index).second){
        h -= vp.at(index).second;
        index++;
      }else{
        h -= mx.second;
        // cerr << ans << " " << (h+ac-1)/ac << endl;
        ans += (h+ac-1)/ac;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}