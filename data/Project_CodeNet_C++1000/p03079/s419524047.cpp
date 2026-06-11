#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int a; cin >>a;
  bool ans=true;
  rep(i,1,3) {
    int b; cin >>b;
    if (a!=b) {
      ans=false;
      break;
    }
  }
  cout <<(ans ? "Yes":"No") <<endl;
  return 0;
}
