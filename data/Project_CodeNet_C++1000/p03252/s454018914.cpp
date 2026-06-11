#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  vector<int> A, B;
  map<char, int> MA;
  for (int i = 0, cnt = 1; i < S.size(); i++) {
    if (!MA[S.at(i)]) MA[S.at(i)] = cnt++;
    A.push_back(MA[S.at(i)]);
  }
  map<char, int> MA2;
  for (int i = 0, cnt = 1; i < T.size(); i++) {
    if (!MA2[T.at(i)]) MA2[T.at(i)] = cnt++;
    B.push_back(MA2[T.at(i)]);
  }
  cout << ((A == B) ? "Yes" : "No") << "\n";
}