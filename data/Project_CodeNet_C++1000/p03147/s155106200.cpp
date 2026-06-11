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
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h.at(i);
  h.insert(h.begin(), 0);
  int ans = 0;
  while(1){
    bool f = false;
    vector<int> nx = h;
    rep(i, n+1){
      if(h.at(i) > 0){
        if(h.at(i-1) <= 0){
          ans++;
          f = true;
        }
        nx.at(i)--;
      }
    }
    h = nx;
    if(f == false) break;
  }
  cout << ans << endl;
  return 0;
}