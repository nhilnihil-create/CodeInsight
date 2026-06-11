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

int fc(string &s){
  int res = 0;
  rep(i, s.size()-1){
    if(s.at(i) == 'A' && s.at(i+1) == 'B')res++;
  }
  return res;
}

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  int ans = 0, ac = 0, bc = 0, abc = 0;
  rep(i, n){
    if(s.at(i).front() == 'B') bc++;
    if(s.at(i).back() == 'A') ac++;
    if(s.at(i).back() == 'A' && s.at(i).front() == 'B') abc++;
    ans += fc(s.at(i));
  }
  ans += min(ac, bc);
  if(ac == abc && bc == abc && abc != 0) ans--;
  cout << ans << endl;
  return 0;
}