#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;

  bool flag = false;

  rep(i, 0, S.size()) {
    if (S == T) {
      flag = true;
      break;
    }
    S = S.back() + S.substr(0, S.size()-1);
  }

  cout << ( flag ? "Yes" : "No" ) << endl;
}
