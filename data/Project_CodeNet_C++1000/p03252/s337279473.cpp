// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
  string S, T;
  cin >> S >> T;
  int sz = S.size();
  vector<vector<int>> p_t(26, vector<int>(26));
  vector<vector<int>> p_s(26, vector<int>(26));
  for (int i = 0; i < sz; i++) {
    p_t[T[i] - 'a'][S[i] - 'a'] = 1;
    p_s[S[i] - 'a'][T[i] - 'a'] = 1;
  }
  for (int i = 0; i < 26; i++) {
    if (accumulate(p_t[i].begin(), p_t[i].end(), 0) > 1 ||
        accumulate(p_s[i].begin(), p_s[i].end(), 0) > 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
