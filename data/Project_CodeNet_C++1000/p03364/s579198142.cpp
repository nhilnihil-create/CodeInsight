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

bool fc(vector<string> &s, int n){
  rep(i, n){
    rep2(j, i+1, n){
      if(s.at(i).at(j) != s.at(j).at(i)) return false;
    }
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  vector<string> sn = s;
  int ans = 0;
  rep(q, n){
    if(fc(sn, n) == true) ans++;
    rep(i, n){
      int ni = (i + q + 1) % n;
      rep(j, n){
        sn.at(i).at(j) = s.at(ni).at(j);
        // cerr << sn.at(i).at(j) << " ";
      }
      // cerr << endl;
    }
  }
  cout << ans*n << endl;
  return 0;
}