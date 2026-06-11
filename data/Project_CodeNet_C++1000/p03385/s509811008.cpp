#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  string S; cin >>S;
  vector<bool> flag(3);
  rep(i,0,3) {
    flag[int(S[i]-97)]=true;
  }
  int count=0;
  rep(i,0,3) {
    if (flag[i]) count++;
  }
  cout <<(count==3 ? "Yes":"No") <<endl;
  return 0;
}
