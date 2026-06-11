#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  string S; cin >>S;
  int MojiNagasa=S.size();
  bool flag=true;
  if (S[0]!='A') flag=false;
  int count=0;
  rep(i,1,MojiNagasa) {
    if (isupper(S[i])) {
      if (i==1 || i==MojiNagasa-1 || S[i]!='C') flag=false;
      count++;
    }
  }
  if (count!=1) flag=false;
  cout <<(flag ? "AC":"WA") <<endl;
}
