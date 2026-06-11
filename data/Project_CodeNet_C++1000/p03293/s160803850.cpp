#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  for (int i = 0; i < 1000; i++) {
    S = S.at(S.size() - 1) + S;
    S.pop_back();
    if (S == T) return cout << "Yes" << "\n", 0;
  }
  cout << "No" << "\n";
}