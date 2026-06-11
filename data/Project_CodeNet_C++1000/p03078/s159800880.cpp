#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector<long> A(X), B(Y), C(Z);
  for (auto &a : A) cin >> a;
  for (auto &b : B) cin >> b;
  for (auto &c : C) cin >> c;

  vector<long> AB;
  for (auto a : A) for (auto b : B) AB.push_back(a + b);
  sort(AB.rbegin(), AB.rend());

  vector<long> ABC;
  for (auto c : C) for (int i = 0; i < min(K, (int)AB.size()); i++) ABC.push_back(AB.at(i) + c);
  sort(ABC.rbegin(), ABC.rend());

  for (int i = 0; i < K; i++) cout << ABC.at(i) << "\n";
}