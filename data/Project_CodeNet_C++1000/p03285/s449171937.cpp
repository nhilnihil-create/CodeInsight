#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
int main() {
  int n;
  cin >> n;
  bool ans=false;
  rep(i,30) {
    rep(j,20) {
      if(4*i+7*j==n) ans=true;
      if(ans) break;
    }
  }
  puts(ans?"Yes":"No");
  return 0;
}