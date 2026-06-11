#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;
  
  bool flag = true;
  if(s[0]!='A') flag = false;

  int cnt = 0;
  for(int i = 2;i<s.size()-1;i++){
    if(s[i]=='C') cnt++;
  }
  if(cnt!=1) flag = false;

  rep(i,s.size())
    if(s[i]!='A' && s[i]!='C'){
      if(!islower(s[i])) flag = false;
    }

  if(flag) cout << "AC" << endl;
  else cout << "WA" << endl;
  
  return 0;
}
