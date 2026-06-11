#include <bits/stdc++.h>
using namespace std;

using pp=pair<int,int>;

int main() {
  string S, T;
  cin >> S >> T;
  S+=S;
  string ans = "No";
  int C=0;
  for (int i=0; i<T.size(); i++) {
    C=0;
    for (int j=0; j<T.size(); j++) {
      if (S[i+j]!=T[j]) {
        C=1;
        break;
      }
    }
    if (C==0) {
      ans = "Yes";
      break;
    }
  }
  cout << ans << endl;
}