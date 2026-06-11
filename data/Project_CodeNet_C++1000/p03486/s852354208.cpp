#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string A, B;
  cin >> A >> B;
  int X = A.size();
  int Y = B.size();
  vector<char> vecA(X);
  vector<char> vecB(Y);
  rep(i, X) {
    vecA.at(i) = A.at(i);
  }
  rep(i, Y) {
    vecB.at(i) = B.at(i);
  }
  sort(vecA.begin(), vecA.end());
  sort(vecB.begin(), vecB.end());
  reverse(vecB.begin(), vecB.end());
  rep(i, X) {
    A.at(i) = vecA.at(i);
  }
  rep(i, Y) {
    B.at(i) = vecB.at(i);
  }
  if(A < B) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}