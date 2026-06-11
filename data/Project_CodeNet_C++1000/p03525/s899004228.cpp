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
  vector<int> p(13, 0);
  vector<int> v;
  p.at(0) = 1;
  rep(i, n){
    int in;
    cin >> in;
    p.at(in)++;
    v.push_back(in);
    if(in == 0 || in == 12){
      if(p.at(in) > 1){
        cout << 0 << endl;
        return 0;
      }
    }else if(p.at(in) > 2){
      cout << 0 << endl;
      return 0;
    }
  }
  int ans = 0;
  rep(bit, 1 << n){
    vector<bool> d(24, false);
    d.at(0) = true;
    bool f = false;
    rep(i, n){
      int nx = v.at(i);
      if((bit & (1 << i)) == 0) nx = 24 - nx;
      if(nx == 24) nx = 0;
      if(d.at(nx) != false){
        f = true;
        break;
      }
      d.at(nx) = true;
    }
    if(f == true) continue;
    int add = 1001001, bf = 0;
    rep2(i, 1, 24){
      if(d.at(i) == true){
        int an = i - bf;
        add = min(add, an);
        bf = i;
      }
    }
    add = min(add, (24 - bf));
    ans = max(ans, add);
  }
  cout << ans << endl;
  return 0;
}