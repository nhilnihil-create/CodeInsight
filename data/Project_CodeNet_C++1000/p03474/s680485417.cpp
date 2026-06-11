#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A, B;
  string S;
  cin >> A >> B >> S;
  int co = 0;
  rep(i, A + B + 1) {
    if(i == A) {
      if(S.at(i) == '-') {
        co++;
      }
    }
    else {
      if(S.at(i) != '-') {
        co++;
      }
    }
  }
  if(co == A + B + 1) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}