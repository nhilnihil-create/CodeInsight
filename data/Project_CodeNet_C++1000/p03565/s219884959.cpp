#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main () {
  string S_prime, T;
  cin >> S_prime >> T;
  bool restorable = false;
  if (S_prime.size() >= T.size()) {
    for (int i = S_prime.size() - T.size(); i >= 0; i--) {
      string sub_S = S_prime.substr(i, T.size());
      for (int j = 0; j < T.size(); j++) {
        if (sub_S.at(j) == T.at(j) || sub_S.at(j) == '?') {
          if (j == T.size() - 1) {
            restorable = true;
            for (int j = 0, k = i; j < T.size(); j++, k++) {
              S_prime.at(k) = T.at(j);
            }
          }
        } else {
          break;
        }
      }
      if (restorable) break;
    }
  }
  if (restorable) {
    for (int i = 0; i < S_prime.size(); i++) {
      if (S_prime.at(i) == '?') S_prime.at(i) = 'a';
    }
    cout << S_prime << endl;
  } else {
    cout << "UNRESTORABLE" << endl;
  }
}