#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  string S; cin >>S;
  int ans=0;
  rep(i,0,4) {
    if (S[i]=='+') ans++;
    else ans--;
  }
  cout <<ans <<endl;
  return 0;
}
