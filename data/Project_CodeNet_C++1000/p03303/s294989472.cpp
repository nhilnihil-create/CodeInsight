#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  string S; cin >>S;
  int w; cin >>w;
  for (int i=0;i<(int)S.size();i+=w) {
    cout <<S[i];
  }
  cout <<endl;
  return 0;
}
