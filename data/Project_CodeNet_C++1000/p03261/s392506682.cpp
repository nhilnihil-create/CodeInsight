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
  char bf = 0;
  bool f = false;
  set<string> se;
  rep(i, n){
    string s;
    cin >> s;
    if(i == 0){
      se.insert(s);
      bf = s.back();
    }else{
      if(s.front() != bf || se.count(s) == 1) f = true;
      se.insert(s);
      bf = s.back();
    }
  }
  if(f == false) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}