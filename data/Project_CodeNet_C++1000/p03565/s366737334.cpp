#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S, T;
  cin >> S >> T;
  if (S.size() < T.size()) {
    cout << "UNRESTORABLE" << endl;
  }
  else {
    int F = S.size();
    int D = T.size();
    vector<char> ans(F);
    for (int j = 0; j < F; j++) {
        ans.at(j) = 'z';
      }
    bool ok = false;
    int K = (S.size() - T.size());
    for (int i = 0; i <= K; i++) {
      vector<char> B(F);
      for (int j = 0; j < F; j++) {
        if (S.at(j) == '?') {
          B.at(j) = 'a';
        }
        else {
          B.at(j) = S.at(j);
        }
      }
      int k = 0;
      bool good = true;
      for (int j = i; j < i + D; j++) {
        if (S.at(j) == '?') {
          B.at(j) = T.at(k);
        }
        else if (S.at(j) != T.at(k)) {
          good = false;
          break;
        }
        else {
          B.at(j) = S.at(j);
        }
        k++;
      }
      if (good) {
        ok = true;
        if (ans > B) {
          for (int j = 0; j < F; j++) {
             ans.at(j) = B.at(j);
          }
        }
      }
    }
    if (ok) {
      for (int j = 0; j < F; j++) {
        cout << ans.at(j);
      }
      cout << endl;
    }
    else {
      cout << "UNRESTORABLE" << endl;
    }
  }
}