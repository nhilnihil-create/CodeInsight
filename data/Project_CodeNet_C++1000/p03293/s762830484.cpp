#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  string S,T; cin >>S >>T;
  rep(i,0,S.size()) {
    if (S==T) {
      cout <<"Yes" <<endl;
      return 0;
    }
    char temp=S[S.size()-1];
    S.erase(S.size()-1); 
    S.insert(S.begin(),temp);
  }
  cout <<"No" <<endl;
  return 0;
}
