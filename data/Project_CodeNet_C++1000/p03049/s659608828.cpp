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
  int fr = 0, re = 0, frre = 0;
  int ans = 0;
  int ad = 0;
  rep(i, n){
    string s;
    cin >> s;
    rep(j, s.size()-1){
      if(s.at(j) == 'A' && s.at(j+1) == 'B') ans++;
    }
    if(s.front() == 'B'){
      if(s.back() == 'A') frre++;
      else fr++;
    }else if(s.back() == 'A') re++;
  }
  cerr << frre << " " << fr << " " << re << " " << ans << endl;
  if(frre >= 1){
    ad += frre-1;
    if(re > 0){
      re--;
      ad++;
    }
    if(fr > 0){
      fr--;
      ad++;
    }
  }
  ad += min(fr, re);
  ans += ad;
  cout << ans << endl;
  return 0;
}