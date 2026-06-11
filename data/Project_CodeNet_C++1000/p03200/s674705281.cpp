#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string str; 
  cin>>str;
  ll bc=0,result=0;
  rep(i,str.size()) {
    if (str[i]=='B') 
      bc++;
    else 
      result+=bc;
  }
  cout<<result;
  return 0;
}
