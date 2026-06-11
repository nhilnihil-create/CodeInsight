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
  string s;
  cin >> s;
  string key = "keyence";
  int co = 0;
  rep(i, key.size()){
    if(s.at(i) != key.at(i)) break;
    co++;
  }
  string ss = s.substr(s.size()-(key.size()-co));
  string skey = key.substr(key.size()-(key.size()-co));
  // cerr << co << " " << ss << " " << skey << endl;
  if(ss == skey){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}