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
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  int ans = 0;
  rep(d, n){
    vector<string> now(n);
    rep(i, n){
      rep(j, n){
        now.at(i).push_back(s.at(i).at((j+d)%n));
      }
    }
    bool f = false;
    rep(i, n){
      rep2(j, i+1, n){
        if(now.at(i).at(j) != now.at(j).at(i)){
          f = true;
        }
      }
    }
    if(f == false) ans += n;
  }
  cout << ans << endl;
  return 0;
}