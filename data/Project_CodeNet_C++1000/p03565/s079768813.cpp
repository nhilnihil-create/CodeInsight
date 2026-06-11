#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string MakeString(string S) {
  for (size_t i = 0; i < S.size(); ++i) {
    if (S[i] == '?') {
      S[i] = 'a';
    }
  }
  return S;
}

int main() {
  string S, T;
  cin >> S >> T;
  vector<string> results;
  for (size_t i = 0, end = S.size() - T.size() + 1; i < end; ++i) {
    if (S[i] == T[0] || S[i] == '?') {
      bool find = true;
      for (size_t j = 0; j < T.size(); ++j) {
        if (S[i+j] != '?' && S[i + j] != T[j]) {
          find = false;
          break;
        }
      }
      if (find) {
        results.push_back(
          MakeString(S.substr(0, i) + T + S.substr(i + T.size(), S.size() - i - T.size())));
      }
    }
  }
  if (results.size()) {
    sort(results.begin(), results.end());
    cout << results[0] << endl;
  } else {
    cout << "UNRESTORABLE" << endl;
  }
  
  return 0;
}
