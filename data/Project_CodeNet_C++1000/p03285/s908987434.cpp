#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int N; cin >>N;
  bool flag=false;
  rep_eq(i,0,100/4) {
    rep_eq(j,0,100/7) {
      if (i*4+j*7==N) {flag=true; break;}
    }
    if (flag) break;
  }
  cout <<(flag ? "Yes":"No") <<endl;
  return 0;
}
