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
  if(s.size() < 26){
    char c;
    set<char> se;
    rep(i, s.size()){
      se.insert(s.at(i));
    }
    rep(i, 26){
      if(se.count(i+'a') == 0){
        c = i+'a';
        break;
      }
    }
    cout << s << c << endl;
    return 0;
  }
  if(s == "zyxwvutsrqponmlkjihgfedcba"){
    cout << -1 << endl;
    return 0;
  }
  string t = s;
  next_permutation(ALL(t));
  rep(i, t.size()){
    cout << t.at(i);
    if(t.at(i) != s.at(i)) break;
  }
  cout << endl;
  return 0;
}