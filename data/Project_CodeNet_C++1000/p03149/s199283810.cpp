#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  vector<char> N(4);
  rep(i,0,4) {
    cin >>N[i];
  }
  sort(N.begin(),N.end());
  string ans="";
  rep(i,0,4) {
    ans+=N[i];
  }
  cout <<(ans=="1479" ? "YES":"NO") <<endl;
  return 0;
}
