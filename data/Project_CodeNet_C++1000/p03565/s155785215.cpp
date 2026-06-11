#include <bits/stdc++.h>
using namespace std;

bool match(const string& S, const string& T, int k) {
  if (k + T.size() <= S.size()){
    for (int i = 0; i < T.size(); i++) {
      if (S.at(i + k) != T.at(i) && S.at(i + k) != '?') {
        return false;
      }
    }
    return true;
  }
  return false;
}

void txt(string& S, const string& T, int k) {
  for (int i = 0; i < T.size(); i++) {
    S.at(i + k) = T.at(i);
  }
  for (int i = 0; i < S.size(); i++) {
    if (S.at(i) == '?') {
      S.at(i) = 'a';
    }
  }
}

int main() {
  string S, T;
  cin >> S >> T;
  bool found = false;
  string ans = S;
  replace(ans.begin(), ans.end(), '?', 'z');
  for (int is = 0; is < S.size(); is++) {
    if(match(S, T, is)){
      string tmpS = S;
      txt(tmpS, T, is);
      ans = min(ans, tmpS);
      found = true;
    }
  }
  if (found) {
    cout << ans << endl;
  } else {
    cout << "UNRESTORABLE" << endl;
  }
}