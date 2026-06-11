#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  string s,t; cin >>s >>t;
  reverse(s.begin(),s.end());
  cout <<(s==t ? "YES":"NO") <<endl;
  return 0;
}
