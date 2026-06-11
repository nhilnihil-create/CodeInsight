#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  string S; cin >>S;
  if (S.size()==3) {
    reverse(S.begin(),S.end());
  }
  cout <<S <<endl;
  return 0;
}
