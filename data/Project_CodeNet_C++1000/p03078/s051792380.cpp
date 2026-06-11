#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector<long> A(X), B(Y), C(Z);
  for (auto &a : A) cin >> a;
  for (auto &b : B) cin >> b;
  for (auto &c : C) cin >> c;

  sort(A.rbegin(), A.rend());
  sort(B.rbegin(), B.rend());
  sort(C.rbegin(), C.rend());

  vector<long> ABC;
  for (int i = 0; i < X; i++) {
    for (int j = 0; j < Y; j++) {
      for (int k = 0; k < Z; k++) {
        if ((i + 1) * (j + 1) * (k + 1) <= K) ABC.push_back(A.at(i) + B.at(j) + C.at(k));
        else break;
      }
    }
  }

  sort(ABC.rbegin(), ABC.rend());

  for (int i = 0; i < K; i++) cout << ABC.at(i) << "\n";
}