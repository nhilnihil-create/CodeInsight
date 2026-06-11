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
  string s;
  cin >> s;
  string key = "keyence";
  rep(i, 7){
    if(s.at(i) != key.at(i)){
      string sb = s.substr(s.size()-key.size()+i, 7-i+1);
      string skey = key.substr(i, key.size()-i+1);
      cerr << sb << " " << skey << endl;
      if(sb == skey) cout << "YES" << endl;
      else cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}