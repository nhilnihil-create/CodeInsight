#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  rep(snip_i, n) cin >> h.at(snip_i);
  int ans = 0;
  while(1){
    bool end = true;
    vector<int> nx = h;
    rep(i, n){
      if(h.at(i) > 0){
        if(i == 0 || h.at(i-1) == 0){
          ans++;
          end = false;
        }
        nx.at(i)--;
      }
    }
    h = nx;
    if(end == true) break;
  }
  cout << ans << endl;
  return 0;
}