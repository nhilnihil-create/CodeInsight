#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string A, B;
  cin >> A >> B;
  string C = A + A;
  int co = 0;
  rep(i, A.size()) {
    rep(j, A.size()) {
      if(C.at(i+j) == B.at(j)) {
        co++;
      }
    }
    if(co == A.size()) {
      break;
    }
    co = 0;
  }
  if(co == 0) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}