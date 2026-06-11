#include <bits/stdc++.h>

using namespace std;

int main() {
  string S;
  int K;
  cin >> S >> K;
  set<string> s;
  for (int i = 0; i < S.length(); i++) {
    for (int j = 1; j <= K; j++) {
      if (i + j > S.length()) break;
      s.insert(S.substr(i, j));
    }
  }
  auto ans = s.begin();
  for (int i = 0; i < K - 1; i++) {
    ans++;
  }
  cout << *ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
