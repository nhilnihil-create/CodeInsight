#include <bits/stdc++.h>
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
using namespace std;

int main() {
  string S;
  cin >> S;
  int ans = 0;
  rep(i, S.size()) {
    rep(j, i+1) {
      bool flag = true;
      for(int k=j; k<=i; k++) {
        if(!(S[k] == 'A' || S[k] == 'C' || S[k] == 'G' || S[k] == 'T')) flag=false;
      }
      if(flag) ans = max(ans, i-j+1);
    }
  }
  cout << ans << endl;
  return 0;
}
