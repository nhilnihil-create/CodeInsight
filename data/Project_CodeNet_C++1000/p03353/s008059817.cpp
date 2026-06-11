#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  int K;
  cin >> s >> K;
  int N = s.length();
  set<string> substrings;
  for (int i = 0; i < N; i++) {
    for (int j = 1; j <= K; j++) {
      if (i + j - 1 > N - 1) break;
      substrings.insert(s.substr(i, j));
    }
  }
  auto itr = substrings.begin();
  for (int i = 0; i < K - 1; i++) {
    itr++;
  }
  cout << (*itr) << endl;

  return 0;
}