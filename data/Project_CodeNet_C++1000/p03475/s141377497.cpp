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
  vector<int> c(n-1), s(n-1), f(n-1);
  rep(i, n-1){
    int a, b, d;
    cin >> a >> b >> d;
    c.at(i) = a; s.at(i) = b; f.at(i) = d;
  }
  rep(i, n){
    int now = 0;
    rep2(j, i, n-1){
      int nx = now % f.at(j);
      if(nx != 0) nx = f.at(j) - nx;
      now = max(s.at(j), (now + nx));
      now += c.at(j);
    }
    cout << now << endl;
  }
  return 0;
}