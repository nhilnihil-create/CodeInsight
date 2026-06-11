#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using ll = long long;

int main(){
  string S;
  cin >> S;
  string ans,e;
  for (int tmp = 0; tmp < 8; tmp++) {
    ans = S[0];
    int sum = stoi(ans);
    rep(i,3){
      e = S[i+1];
        if ((tmp>>(2-i))&1){
          sum += stoi(e);
          ans = ans + "+" + e;
        }
        else {
          sum -= stoi(e);
          ans = ans + "-" + e;
        }
    }
    if (sum == 7){
      cout << ans + "=7" << endl;
      return 0;
    }
  }
}