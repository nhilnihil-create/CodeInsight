#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S;
  T = S;

  if (S.size() < 26)
    for (char c = 'a'; c <= 'z'; c++)
      if (!count(S.begin(), S.end(), c)) return cout << S + c << "\n", 0;

  if (!next_permutation(S.begin(), S.end())) return cout << -1 << "\n", 0;

  for (int i = 0; i < S.size(); i++) {
    cout << S.at(i);
    if (S.at(i) != T.at(i)) return cout << "\n", 0;
  }
}