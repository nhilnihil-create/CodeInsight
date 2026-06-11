#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

string fc(int fr, int to, int co){
  string ret;
  ret += to_string(fr);
  ret.push_back(' ');
  ret += to_string(to);
  ret.push_back(' ');
  ret += to_string(co);
  
  return ret;
}

int main(){
  int l;
  cin >> l;
  int r = log2(l);
  vector<string> ans;
  rep(i, r){
    ans.push_back(fc(i+1, i+2, 0));
    ans.push_back(fc(i+1, i+2, (1 << i)));
  }
  rrep(i, r+1){
    if(i == 0) break;
    int t = i;
    // cerr << t << endl;
    if(l - (1 << (t - 1)) >= (1 << r)){
      ans.push_back(fc(t, r+1, (l - (1 << (t-1)))));
      l -= (1 << (t-1));
    }
  }
  cout << r+1 << " " << ans.size() << endl;
  for(auto s : ans){
    cout << s << endl;
  }
  return 0;
}