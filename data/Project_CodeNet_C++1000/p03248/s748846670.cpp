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
  int n = s.size();
  bool f = (s.back() == '1' || s.front() == '0');
  s.pop_back();
  string sr = s;
  reverse(sr.begin(), sr.end());
  if(f == true || sr != s){
    cout << -1 << endl;
    return 0;
  }
  vector<int> from;
  rep(i, n-1){
    if(i == n-2){
      cout << i+1 << " " << i+2 << endl;
    }
    if(s.at(i) == '1'){
      for(int j : from){
        cout << j+1 << " " << i+1 << endl;
      }
      from.clear();
    }
    from.push_back(i);
  }
  return 0;
}