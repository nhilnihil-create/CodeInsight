#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
  string s, t;
  cin >> s >> t;
  vector<int> s2t(26, -1), t2s(26, -1);
  rep(i, s.size()){
    char sn = s.at(i) - 'a';
    char tn = t.at(i) - 'a';
    if(s2t.at(sn) == -1) s2t.at(sn) = tn;
    else{
      if(s2t.at(sn) != tn){
        cout << "No" << endl;
        return 0;
      }
    }
    if(t2s.at(tn) == -1) t2s.at(tn) = sn;
    else{
      if(t2s.at(tn) != sn){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}