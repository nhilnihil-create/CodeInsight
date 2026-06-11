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
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  vector<int> ans;
  while(b.size() > 0){
    int co = b.size();
    rrepit(itr, b){
      if(*itr == co){
        auto er = b.begin();
        rep(_, co-1) er++;
        b.erase(er);
        ans.push_back(co);
        co = -1;
        break;
      }
      co--;
    }
    if(co != -1){
      cout << -1 << endl;
      return 0;
    }
  }
  reverse(ALL(ans));
  for(auto i : ans){
    cout << i << endl;
  }
  return 0;
}