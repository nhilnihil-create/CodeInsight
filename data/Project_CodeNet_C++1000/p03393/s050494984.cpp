#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  if (S.size() < 26) {
    for (char c = 'a'; c <= 'z'; c++) {
      if (!count(S.begin(), S.end(), c)) return cout << S + c << "\n", 0;
    } 
  } else {
    if (S == "zyxwvutsrqponmlkjihgfedcba") return cout << -1 << "\n", 0;
    for (int i = S.size() - 1; i >= 0; i--) {
      do S.at(i)++;
      while (count(S.begin(), S.end() - 1, S.at(i)));
      if (S.at(i) <= 'z') return cout << S << "\n", 0;
      S.pop_back();
    }
  }
}