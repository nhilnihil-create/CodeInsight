#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int K;
  cin >> S >> K;
  set<string> SE;
  for (int i = 0; i < S.size(); i++) {
    for (int j = 0; j <= i; j++) {
      if (i - j + 1 > K) continue;
      SE.insert(S.substr(j, i - j + 1));
    }
  }
  cout << *next(SE.begin(), K - 1) << "\n";
}