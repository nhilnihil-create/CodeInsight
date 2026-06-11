#include <bits/stdc++.h>
using namespace std;
int main() {
  string S, T;
  cin >> S >> T;
  int match[26];
  for (int i = 0; i < 26; i++) {
    match[i] = -1;
  }
  for (int i = 0; i < S.length(); i++) {
    if (match[S[i] - 'a'] == -1) {
      match[S[i] - 'a'] = T[i] - 'a';
    }
    else if (match[S[i] - 'a'] == T[i] - 'a') {
      continue;
    }
    else {
      cout << "No";
      return 0;
    }
  }
  for (int i = 0; i < 26; i++) {
    match[i] = -1;
  }
  for (int i = 0; i < T.length(); i++) {
    if (match[T[i] - 'a'] == -1) {
      match[T[i] - 'a'] = S[i] - 'a';
    }
    else if (match[T[i] - 'a'] == S[i] - 'a') {
      continue;
    }
    else {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}