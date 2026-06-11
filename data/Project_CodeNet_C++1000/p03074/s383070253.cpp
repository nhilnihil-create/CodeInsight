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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  s.push_back('x');
  vector<pair<char, int>> vp;
  pair<char, int> p = make_pair(s.front(), 1);
  rep2(i, 1, n+1){
    if(p.first != s.at(i)){
      vp.push_back(p);
      p = make_pair(s.at(i), 1);
    }else p.second++;
  }
  // for(auto p : vp){
  //   cerr << p.first << p.second << " ";
  // }
  // cerr << endl;
  int ans = -1, sum = 0, l = 0, co = 0;
  rep(i, vp.size()){
    if(vp.at(i).first == '0') co++;
    if(co == k+1){
      ans = max(ans, sum);
      sum -= vp.at(l).second;
      co--;
      if(vp.at(l).first == '1'){
        l++;
        sum -= vp.at(l).second;
      }
      l++;
    }
    sum += vp.at(i).second;
  }
  ans = max(ans, sum);
  cout << ans << endl;
  return 0;
}