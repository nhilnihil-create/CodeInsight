#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s,t; cin >> s >> t;

  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  reverse(t.begin(),t.end());
  
  bool ok = false;
  if(s<t) ok = true;
  /*rep(i,s.size()){
    if(t.size()>i){
      if(s[i]<t[i]) ok = true;
      break;
    }
  }
  if(s.size()<t.size()){
    rep(i,s.size())
      if(s[i]==t[i]) ok = true;
  }
  */
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
